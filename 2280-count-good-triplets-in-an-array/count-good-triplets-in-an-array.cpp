#include <vector>

using namespace std;

class Solution {
    vector<int> tree;

    void update(int node, int start, int end, int idx) {
        if (start == end) {
            tree[node]++; // Mark this value as seen
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node + 1, start, mid, idx);
        } else {
            update(2 * node + 2, mid + 1, end, idx);
        }
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return 0; // Out of bounds
        }
        if (l <= start && end <= r) {
            return tree[node]; // Completely inside
        }
        int mid = start + (end - start) / 2;
        int p1 = query(2 * node + 1, start, mid, l, r);
        int p2 = query(2 * node + 2, mid + 1, end, l, r);
        return p1 + p2;
    }

public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        tree.assign(4 * n, 0);
        vector<int> pos_map(n);
        
        for (int i = 0; i < n; ++i) {
            pos_map[nums1[i]] = i;
        }
        
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            A[i] = pos_map[nums2[i]];
        }

        long long total_triplets = 0;

        for (int i = 0; i < n; ++i) {
            int current_val = A[i];
            
            long long left_smaller = 0;
            // Query only if current_val > 0 to avoid invalid range [0, -1]
            if (current_val > 0) {
                left_smaller = query(0, 0, n - 1, 0, current_val - 1);
            }
            
            long long left_greater = i - left_smaller;
            long long total_greater = (n - 1) - current_val;
            long long right_greater = total_greater - left_greater;

            total_triplets += (left_smaller * right_greater);

            // Update Segment Tree for the current value
            update(0, 0, n - 1, current_val);
        }

        return total_triplets;
    }
};