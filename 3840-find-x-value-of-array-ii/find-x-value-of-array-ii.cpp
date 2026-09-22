#include <vector>

using namespace std;

class Solution {
private:
    int k_val;
    int n_val;
    vector<int> tree_prod;
    vector<int> tree_prefix;

    void push_up(int node, int left_child, int right_child) {
        int pL = tree_prod[left_child];
        int pR = tree_prod[right_child];
        tree_prod[node] = (1LL * pL * pR) % k_val;

        int offset_node = node * k_val;
        int offset_L = left_child * k_val;
        int offset_R = right_child * k_val;

        for (int r = 0; r < k_val; ++r) {
            tree_prefix[offset_node + r] = tree_prefix[offset_L + r];
        }

        for (int r = 0; r < k_val; ++r) {
            int cnt = tree_prefix[offset_R + r];
            if (cnt > 0) {
                int new_r = (1LL * pL * r) % k_val;
                tree_prefix[offset_node + new_r] += cnt;
            }
        }
    }

    void build(const vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            int rem = nums[start] % k_val;
            tree_prod[node] = rem;
            tree_prefix[node * k_val + rem] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        build(nums, 2 * node, start, mid);
        build(nums, 2 * node + 1, mid + 1, end);
        push_up(node, 2 * node, 2 * node + 1);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            int rem = val % k_val;
            tree_prod[node] = rem;
            int offset = node * k_val;
            for (int r = 0; r < k_val; ++r) {
                tree_prefix[offset + r] = 0;
            }
            tree_prefix[offset + rem] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        push_up(node, 2 * node, 2 * node + 1);
    }

    void get_canonical_nodes(int node, int start, int end, int l, int r, vector<int>& nodes) {
        if (l <= start && end <= r) {
            nodes.push_back(node);
            return;
        }
        int mid = start + (end - start) / 2;
        if (l <= mid) {
            get_canonical_nodes(2 * node, start, mid, l, r, nodes);
        }
        if (r > mid) {
            get_canonical_nodes(2 * node + 1, mid + 1, end, l, r, nodes);
        }
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        k_val = k;
        n_val = nums.size();

        tree_prod.assign(4 * n_val, 0);
        tree_prefix.assign(4 * n_val * k_val, 0);

        build(nums, 1, 0, n_val - 1);

        vector<int> result;
        result.reserve(queries.size());
        vector<int> canonical_nodes;

        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start_idx = q[2];
            int target_x = q[3];

            update(1, 0, n_val - 1, idx, val);

            canonical_nodes.clear();
            get_canonical_nodes(1, 0, n_val - 1, start_idx, n_val - 1, canonical_nodes);

            int ans = 0;
            int curr_prod = 1;

            for (int u : canonical_nodes) {
                int offset = u * k_val;
                for (int r = 0; r < k_val; ++r) {
                    int cnt = tree_prefix[offset + r];
                    if (cnt > 0) {
                        if ((1LL * curr_prod * r) % k_val == target_x) {
                            ans += cnt;
                        }
                    }
                }
                curr_prod = (1LL * curr_prod * tree_prod[u]) % k_val;
            }

            result.push_back(ans);
        }

        return result;
    }
};