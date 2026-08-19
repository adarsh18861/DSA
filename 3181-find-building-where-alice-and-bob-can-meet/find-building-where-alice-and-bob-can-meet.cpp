#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> tree;
    
    void build(int node, int l, int r, const vector<int>& heights) {
        if (l == r) {
            tree[node] = heights[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node + 1, l, mid, heights);
        build(2 * node + 2, mid + 1, r, heights);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }
    
    int query(int node, int l, int r, int ql, int qr, int target, const vector<int>& heights) {
        if (l > qr || r < ql || tree[node] <= target) {
            return -1;
        }
        if (l == r) {
            return l;
        }
        int mid = l + (r - l) / 2;
        int left_res = query(2 * node + 1, l, mid, ql, qr, target, heights);
        if (left_res != -1) {
            return left_res;
        }
        return query(2 * node + 2, mid + 1, r, ql, qr, target, heights);
    }

public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        tree.assign(4 * n, 0);
        build(0, 0, n - 1, heights);
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int a = q[0], b = q[1];
            if (a > b) swap(a, b);
            
            if (a == b || heights[a] < heights[b]) {
                ans.push_back(b);
            } else {
                int res = query(0, 0, n - 1, b + 1, n - 1, heights[a], heights);
                ans.push_back(res);
            }
        }
        return ans;
    }
};