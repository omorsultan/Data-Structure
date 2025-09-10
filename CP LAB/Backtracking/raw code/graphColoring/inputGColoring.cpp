#include <iostream>
#include <vector>
using namespace std;

// Check if assigning color c to vertex v is safe
bool isSafe(int v, vector<vector<int>>& graph, vector<int>& colors, int c) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[v][i] && colors[i] == c) // Adjacent vertex has same color
            return false;
    }
    return true;
}

// Backtracking function
bool solveGraphColoring(vector<vector<int>>& graph, int m, vector<int>& colors, int v) {
    if (v == graph.size()) {
        // All vertices colored, print solution
        cout << "[ ";
        for (int col : colors) cout << col << " ";
        cout << "]" << endl;
        return true;
    }

    bool found = false;
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, colors, c)) {
            colors[v] = c; // Assign color
            if (solveGraphColoring(graph, m, colors, v + 1))
                found = true;
            colors[v] = 0; // Backtrack
        }
    }
    return found;
}

int main() {
    int n, e, m;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    // Initialize adjacency matrix
    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter edges (u v) as 0-based indices:" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; // Undirected graph
    }

    cout << "Enter number of colors allowed: ";
    cin >> m;

    vector<int> colors(n, 0);
    cout << "Graph coloring solutions:" << endl;

    if (!solveGraphColoring(graph, m, colors, 0)) {
        cout << "No solution exists with " << m << " colors." << endl;
    }

    return 0;
}
