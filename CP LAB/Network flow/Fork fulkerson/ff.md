content = """# Ford-Fulkerson Algorithm (Steps)

# 1. Initialize Flow
- Set flow on every edge = 0.

## 2. Build Residual Graph
- For each edge (u, v) with capacity c and flow f:
  - Residual capacity = c - f.
  - Add reverse edge (v, u) with residual capacity = f.

## 3. Find Augmenting Path
- Search for a path from source **s** to sink **t** in the residual graph.
- Path must have positive residual capacity on all edges.
- Can use **DFS (depth-first search)** or **BFS (breadth-first search)**.

## 4. Check if Path Exists
- If no augmenting path is found → **stop** (current flow is max).

## 5. Find Minimum Residual Capacity (Bottleneck)
- Let **C** = minimum residual capacity of edges along the found path.

## 6. Update Flows
- For each edge (u, v) in the path:
  - Increase flow: f(u, v) += C
  - Decrease reverse flow: f(v, u) -= C

## 7. Repeat
- Go back to Step 2 until no augmenting path exists.
"""

with open("/mnt/data/Ford_Fulkerson.md", "w") as f:
    f.write(content)

"/mnt/data/Ford_Fulkerson.md"
