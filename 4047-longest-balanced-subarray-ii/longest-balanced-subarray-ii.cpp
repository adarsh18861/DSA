#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    struct Node {
        int min_val = 0;
        int max_val = 0;
        int lazy = 0;
    };

    vector<Node> tree;

    void push(int node, int start, int end) {
        if (tree[node].lazy != 0) {
            tree[node].min_val += tree[node].lazy;
            tree[node].max_val += tree[node].lazy;

            if (start != end) {
                tree[2 * node + 1].lazy += tree[node].lazy;
                tree[2 * node + 2].lazy += tree[node].lazy;
            }
            tree[node].lazy = 0;
        }
    }

    void updateRange(int node, int start, int end, int l, int r, int val) {
        push(node, start, end);

        if (start > r || end < l) return;

        if (start >= l && end <= r) {
            tree[node].lazy += val;
            push(node, start, end);
            return;
        }

        int mid = start + (end - start) / 2;
        updateRange(2 * node + 1, start, mid, l, r, val);
        updateRange(2 * node + 2, mid + 1, end, l, r, val);

        tree[node].min_val = min(tree[2 * node + 1].min_val, tree[2 * node + 2].min_val);
        tree[node].max_val = max(tree[2 * node + 1].max_val, tree[2 * node + 2].max_val);
    }

    int queryLeftmostZero(int node, int start, int end, int l, int r) {
        push(node, start, end);

        if (start > r || end < l || tree[node].min_val > 0 || tree[node].max_val < 0) {
            return -1;
        }

        if (start == end) {
            return (tree[node].min_val == 0) ? start : -1;
        }

        int mid = start + (end - start) / 2;

        int left_res = queryLeftmostZero(2 * node + 1, start, mid, l, r);
        if (left_res != -1) {
            return left_res;
        }

        return queryLeftmostZero(2 * node + 2, mid + 1, end, l, r);
    }

public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        tree.assign(4 * n, Node());
        unordered_map<int, int> last_pos;

        int max_len = 0;

        for (int r = 0; r < n; ++r) {
            int val = nums[r];
            int prev_idx = last_pos.count(val) ? last_pos[val] : -1;
            int diff = (val % 2 == 0) ? 1 : -1;

            updateRange(0, 0, n - 1, prev_idx + 1, r, diff);

            int l = queryLeftmostZero(0, 0, n - 1, 0, r);
            if (l != -1) {
                max_len = max(max_len, r - l + 1);
            }

            last_pos[val] = r;
        }

        return max_len;
    }
};