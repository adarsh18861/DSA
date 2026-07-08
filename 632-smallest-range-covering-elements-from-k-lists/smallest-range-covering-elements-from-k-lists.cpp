#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        typedef pair<int, pair<int, int>> P;
        priority_queue<P, vector<P>, greater<P>> min_heap;
        
        int current_max = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++) {
            min_heap.push({nums[i][0], {i, 0}});
            current_max = max(current_max, nums[i][0]);
        }
        
        int range_start = min_heap.top().first;
        int range_end = current_max;
        
        while (!min_heap.empty()) {
            auto curr = min_heap.top();
            min_heap.pop();
            
            int current_min = curr.first;
            int list_idx = curr.second.first;
            int elem_idx = curr.second.second;
            
            if ((current_max - current_min) < (range_end - range_start)) {
                range_start = current_min;
                range_end = current_max;
            }
            
            if (elem_idx + 1 < nums[list_idx].size()) {
                int next_val = nums[list_idx][elem_idx + 1];
                min_heap.push({next_val, {list_idx, elem_idx + 1}});
                current_max = max(current_max, next_val);
            } else {
                break;
            }
        }
        
        return {range_start, range_end};
    }
};