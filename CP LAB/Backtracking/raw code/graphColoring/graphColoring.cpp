#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& colors, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] && colors[i] == c) // Adjacent vertex has same color
            return false;
    }
    return true;
}

bool solveGraphColoring(vector<vector<int>>& graph, int m, vector<int>& colors, int v) {
    if (v == graph.size()) {
        // All vertices colored, print solution
        cout << "[ ";
        for (int col : colors) cout << col << " ";
        cout << "]" << endl;
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, colors, c)) {
            colors[v] = c; // Assign color
            solveGraphColoring(graph, m, colors, v + 1);
            colors[v] = 0; // Backtrack
        }
    }

    return false;
}

int main() {
    int n = 4; // Number of vertices
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3; // Number of colors allowed

    vector<int> colors(n, 0);
    cout << "Graph coloring solutions:" << endl;
    solveGraphColoring(graph, m, colors, 0);

    return 0;
}
