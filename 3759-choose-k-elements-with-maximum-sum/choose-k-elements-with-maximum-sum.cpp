#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long> answer(n, 0);
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return nums1[a] < nums1[b];
        });

        priority_queue<int, vector<int>, greater<int>> min_heap;
        long long current_heap_sum = 0;
        
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && nums1[indices[j]] == nums1[indices[i]]) {
                answer[indices[j]] = current_heap_sum;
                j++;
            }

            for (int idx = i; idx < j; idx++) {
                min_heap.push(nums2[indices[idx]]);
                current_heap_sum += nums2[indices[idx]];
                
                if (min_heap.size() > k) {
                    current_heap_sum -= min_heap.top();
                    min_heap.pop();
                }
            }
            
            i = j;
        }

        return answer;
    }
};

/*
EXPLANATION OF THE APPROACH:

1. Index Map Sorting:
Instead of rewriting or destroying the alignment between nums1 and nums2, we create an auxiliary 'indices' vector containing [0, 1, ..., n-1]. We sort this index tracker based on the values inside nums1 in ascending order. This allows us to walk through nums1 from the smallest element to the largest element while retaining perfect access to the paired values in nums2.

2. Grouping Equal Elements (The Two-Pointer Loop):
The inner while loop (tracked by variable 'j') dynamically collects all adjacent indices that share the exact same value in nums1. Because the condition dictates that nums1[j] must be strictly less than nums1[i], elements with identical values cannot look at each other's nums2 metrics. Thus, we assign the current 'current_heap_sum' to all identical elements first, before they are allowed to contribute their own nums2 values to the heap.

3. Top-K Maintenance:
Once all identical elements at the current value layer have received their calculated sum, we run a separate loop from 'i' to 'j' to push their respective nums2 values into our min-heap. If pushing an element pushes our min-heap size past our boundary constraint limit 'k', we pop the smallest item out from the top. We continuously track this running aggregation inside 'current_heap_sum' with O(1) mathematical updates instead of resetting the heap sum repeatedly.

4. Efficiency:
Every index is pushed and popped from the heap at most once, which bounds the runtime profile to O(N log K) after sorting. Using 64-bit 'long long' formatting for the return array prevents overflow anomalies when summing up high-frequency sub-components.
*/