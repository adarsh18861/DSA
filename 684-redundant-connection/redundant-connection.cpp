#include <vector>
#include <numeric>

using namespace std;

// Disjoint Set Union (DSU) Data Structure
class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
        rank.assign(n + 1, 0);
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Path Compression
    }

    bool unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u == root_v) {
            return false; // Cycle detected: u and v are already connected
        }

        // Union by Rank
        if (rank[root_u] < rank[root_v]) {
            swap(root_u, root_v);
        }
        parent[root_v] = root_u;
        if (rank[root_u] == rank[root_v]) {
            rank[root_u]++;
        }

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // If union fails, this edge connects two already-connected nodes (forms a cycle)
            if (!dsu.unite(u, v)) {
                return edge;
            }
        }

        return {};
    }
};