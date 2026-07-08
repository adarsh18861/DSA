#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for (int num : nums) {
            pq.push(num);
        }
        
        int operations = 0;
        
        while (pq.size() >= 2 && pq.top() < k) {
            long long x = pq.top();
            pq.pop();
            
            long long y = pq.top();
            pq.pop();
            
            long long new_val = x * 2 + y;
            pq.push(new_val);
            
            operations++;
        }
        
        return operations;
    }
};

/*
EXPLANATION OF THE APPROACH:

1. Always Fetching the Two Smallest Elements:
The problem requires us to repeatedly pick and remove the two smallest elements from the array. A Min-Heap (priority_queue with greater<long long>) dynamically organizes the data so that the absolute smallest element is always available at the top in O(1) lookups and O(log N) extractions.

2. Simulating the Operations Greedily:
Since the array elements are processed from the smallest upwards, we pop the smallest element 'x' followed by the next smallest element 'y'. Because it is a min-heap, x will always be less than or equal to y, making min(x, y) = x and max(x, y) = y. We apply the formula (x * 2 + y) and push the combined result back into the heap.

3. Preventing Integer Overflow:
The problem constraints indicate that elements can grow rapidly due to the multiplication step (x * 2 + y). If we keep the variables as standard 32-bit integers, they will quickly overflow. To handle massive numbers correctly, the min-heap and the intermediate variables (x, y, new_val) are defined using 64-bit 'long long' precision.

4. Loop Termination Condition:
The simulation runs under two conditions inside the while loop:
- There must be at least two elements left in the heap to perform an operation.
- The smallest element currently in the heap (pq.top()) must be strictly less than k. The moment the top element becomes greater than or equal to k, we can guarantee all other remaining elements are also greater than or equal to k, so we terminate and return the operations counter.
*/