#include <bits/stdc++.h>
using namespace std;
#define int int
struct Point {
    int x, y;
};

// To find orientation of ordered triplet (p, q, r).
// Returns:
// 0 -> collinear
// 1 -> clockwise
// 2 -> counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (int)(q.y - p.y) * (r.x - q.x) - (int)(q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;          // collinear
    return (val > 0) ? 1 : 2;        // 1->clockwise, 2->counterclockwise
}

// Distance squared (for tie-breaking in sorting)
int distSq(Point p1, Point p2) {
    return (int)(p1.x - p2.x) * (p1.x - p2.x) +
           (int)(p1.y - p2.y) * (p1.y - p2.y);
}

Point p0; // global pivot

// Comparator for sorting points by polar angle w.r.t p0
bool compare(Point p1, Point p2) {
    int o = orientation(p0, p1, p2);
    if (o == 0) return distSq(p0, p1) < distSq(p0, p2);
    return (o == 2); // counterclockwise first
}

// Graham Scan function
vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return {}; // convex hull not possible

    // Step 1: Find bottom-most point (pivot)
    int ymin = points[0].y, minIdx = 0;
    for (int i = 1; i < n; i++) {
        if ((points[i].y < ymin) ||(points[i].y == ymin && points[i].x < points[minIdx].x))
        {
            ymin = points[i].y;
            minIdx = i;
        }
    }
    swap(points[0], points[minIdx]);
    p0 = points[0];

    // Step 2: Sort points by polar angle
    sort(points.begin() + 1, points.end(), compare);

    // Step 3: Remove collinear points keeping the farthest
    vector<Point> filtered;
    filtered.push_back(points[0]);
    for (int i = 1; i < n; i++) {
        while (i < n - 1 && orientation(p0, points[i], points[i + 1]) == 0)
            i++;
        filtered.push_back(points[i]);
    }

    // Step 4: Build hull using stack
    if (filtered.size() < 3) return {}; // convex hull not possible

    stack<Point> st;
    st.push(filtered[0]);
    st.push(filtered[1]);
    st.push(filtered[2]);
    // explain below for loop
    // This loop processes each point in the filtered list starting from the 3rd point
    for (int i = 3; i < filtered.size(); i++) {
        while (st.size() > 1) {
            Point top = st.top(); st.pop();
            Point nextTop = st.top();
            if (orientation(nextTop, top, filtered[i]) == 2) {
                st.push(top);
                break;
            }
        }
        st.push(filtered[i]);
    }

    // Collect hull points
    vector<Point> hull;
    while (!st.empty()) {
        hull.push_back(st.top());
        st.pop();
    }
    reverse(hull.begin(), hull.end());
    return hull;
}

// Driver code
signed main() {
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
                            {3, 0}, {0, 0}, {3, 3}};
    vector<Point> hull = convexHull(points);

    cout << "Convex Hull points:\n";
    for (auto p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
    return 0;
}
