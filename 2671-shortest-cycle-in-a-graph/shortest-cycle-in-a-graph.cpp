#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        // 1. Construct Adjacency List for Bi-directional Graph
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int minCycle = 1e9; // Initialize with a large sentinel value

        // 2. Perform BFS starting from every vertex
        for (int i = 0; i < n; i++) {
            vector<int> dist(n, -1);
            vector<int> parent(n, -1);
            queue<int> q;

            dist[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    // Case A: Unvisited neighbor
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    }
                    // Case B: Visited neighbor that is NOT the immediate parent
                    else if (parent[u] != v) {
                        minCycle = min(minCycle, dist[u] + dist[v] + 1);
                    }
                }
            }
        }

        // 3. Return result
        return (minCycle == 1e9) ? -1 : minCycle;
    }
};