#include <bits/stdc++.h>
using namespace std;

// BFS to find augmenting path
bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent) {
    int V = rGraph.size();
    vector<bool> visited(V, false);

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                parent[v] = u;
                visited[v] = true;
                if (v == t) return true; // reached sink
                q.push(v);
            }
        }
    }
    return false;
}

// Ford-Fulkerson (using Edmonds-Karp BFS)
int fordFulkerson(vector<vector<int>>& graph, int s, int t) {
    int V = graph.size();
    vector<vector<int>> rGraph = graph; // residual graph
    vector<int> parent(V);

    int max_flow = 0;

    // Augment while path exists
    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;

        // find minimum capacity in path (bottleneck)
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // update residual capacities
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }
    return max_flow;
}

int main() {
    // Example graph
    //  s=0, A=1, B=2, t=3
    
    vector<vector<int>> graph = {
        {0, 10, 5, 0},   // s → A (10), s → B (5)
        {0, 0, 15, 10},  // A → B (15), A → t (10)
        {0, 0, 0, 10},   // B → t (10)
        {0, 0, 0, 0}     // sink
    };

    int s = 0, t = 3;
    cout << "Maximum Flow = " << fordFulkerson(graph, s, t) << endl;

    return 0;
}
