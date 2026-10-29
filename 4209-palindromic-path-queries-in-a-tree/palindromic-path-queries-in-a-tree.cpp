#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> adj;
    vector<int> sz, dep, parent, heavy, head, pos;
    vector<int> tree;
    int cur_pos;

    void dfs_sz(int u, int p, int d) {
        sz[u] = 1;
        dep[u] = d;
        parent[u] = p;
        int max_sz = 0;
        for (int v : adj[u]) {
            if (v != p) {
                dfs_sz(v, u, d + 1);
                sz[u] += sz[v];
                if (sz[v] > max_sz) {
                    max_sz = sz[v];
                    heavy[u] = v;
                }
            }
        }
    }

    void dfs_hld(int u, int h) {
        head[u] = h;
        pos[u] = cur_pos++;
        if (heavy[u] != -1) {
            dfs_hld(heavy[u], h);
        }
        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u]) {
                dfs_hld(v, v);
            }
        }
    }

    void update_tree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (start <= idx && idx <= mid)
            update_tree(2 * node, start, mid, idx, val);
        else
            update_tree(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    int query_tree(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return 0;
        if (l <= start && end <= r)
            return tree[node];
        int mid = start + (end - start) / 2;
        return query_tree(2 * node, start, mid, l, r) ^ query_tree(2 * node + 1, mid + 1, end, l, r);
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        sz.resize(n);
        dep.resize(n);
        parent.resize(n);
        heavy.assign(n, -1);
        head.resize(n);
        pos.resize(n);
        cur_pos = 0;

        dfs_sz(0, -1, 0);
        dfs_hld(0, 0);

        tree.assign(4 * n, 0);

        for (int i = 0; i < n; ++i) {
            update_tree(1, 0, n - 1, pos[i], 1 << (s[i] - 'a'));
        }

        vector<bool> ans;
        for (const auto& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                s[u] = c;
                update_tree(1, 0, n - 1, pos[u], 1 << (c - 'a'));
            } else if (type == "query") {
                int u, v;
                ss >> u >> v;
                int path_xor = 0;
                while (head[u] != head[v]) {
                    if (dep[head[u]] < dep[head[v]]) swap(u, v);
                    path_xor ^= query_tree(1, 0, n - 1, pos[head[u]], pos[u]);
                    u = parent[head[u]];
                }
                if (dep[u] > dep[v]) swap(u, v);
                path_xor ^= query_tree(1, 0, n - 1, pos[u], pos[v]);

                int odd_count = __builtin_popcount(path_xor);
                ans.push_back(odd_count <= 1);
            }
        }
        return ans;
    }
};