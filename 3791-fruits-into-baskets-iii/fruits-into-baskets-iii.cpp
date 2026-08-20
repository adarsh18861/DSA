#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<int> tree;

    void build(int node, int start, int end, const vector<int>& baskets) {
        if (start == end) {
            tree[node] = baskets[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node + 1, start, mid, baskets);
        build(2 * node + 2, mid + 1, end, baskets);
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int query(int node, int start, int end, int fruit_qty) {
        if (tree[node] < fruit_qty) {
            return -1; 
        }
        if (start == end) {
            return start; 
        }
        
        int mid = start + (end - start) / 2;
        
       
        if (tree[2 * node + 1] >= fruit_qty) {
            return query(2 * node + 1, start, mid, fruit_qty);
        } else {
            return query(2 * node + 2, mid + 1, end, fruit_qty);
        }
    }

   
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val; 
            return;
        }
        
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node + 1, start, mid, idx, val);
        } else {
            update(2 * node + 2, mid + 1, end, idx, val);
        }
        
       
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        tree.assign(4 * n, 0);
        build(0, 0, n - 1, baskets);
        
        int unplaced_count = 0;
        
        for (int i = 0; i < fruits.size(); ++i) {
         
            int target_index = query(0, 0, n - 1, fruits[i]);
            
           
            if (target_index != -1) {
                update(0, 0, n - 1, target_index, 0); 
            } else {
                unplaced_count++;
            }
        }
        
        return unplaced_count;
    }
};