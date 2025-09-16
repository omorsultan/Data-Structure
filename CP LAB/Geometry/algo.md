# Graham’s Scan Algorithm (Pseudocode)
 https://www.youtube.com/watch?v=B2AJoQSZf4M&ab_channel=StableSort
```cpp
Algorithm GrahamScan(points[], n):
 
1.  if n < 3: 
        return {}   // Convex hull not possible 
 
2.  // Step 1: Find pivot (lowest y, if tie then lowest x) 
    pivot = points[0] 
    for i = 1 to n-1: 
        if (points[i].y < pivot.y) OR 
           (points[i].y == pivot.y AND points[i].x < pivot.x): 
            pivot = points[i] 
 
    swap(pivot, points[0])   // put pivot at index 0 
 
3.  // Step 2: Sort remaining points by polar angle w.r.t pivot 
    sort(points[1..n-1], compareByAngle) 
 
    // In compareByAngle(p1, p2): 
    //    o = orientation(pivot, p1, p2) 
    //    if o == collinear: 
    //         keep the farthest one last 
    //    else if o == counterclockwise: 
    //         p1 comes before p2 
    //    else: 
    //         p2 comes before p1 
 
4.  // Step 3: Remove unnecessary collinear points 
    filtered = [] 
    filtered.push_back(points[0]) 
    for i = 1 to n-1: 
        while i < n-1 AND orientation(pivot, points[i], points[i+1]) == collinear: 
            i++ 
        filtered.push_back(points[i]) 
 
    if filtered.size() < 3: 
        return {}   // Convex hull not possible 
 
5.  // Step 4: Build convex hull using stack 
    stack = empty 
    push(filtered[0]) 
    push(filtered[1]) 
    push(filtered[2]) 
 
    for i = 3 to filtered.size()-1: 
        while stack has >= 2 points AND 
              orientation(nextToTop(stack), top(stack), filtered[i]) != counterclockwise: 
            pop(stack)   // remove right turns 
        push(filtered[i]) 
 
6.  // Step 5: Stack contains convex hull vertices 
    hull = [] 
    while stack not empty: 
        hull.push_back(pop(stack)) 
 
    reverse(hull)   // to get CCW order 
    return hull 
```
