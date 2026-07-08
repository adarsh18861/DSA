#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        typedef pair<int, int> P;
        priority_queue<P, vector<P>, greater<P>> pq;

        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        vector<bool> marked(n, false);
        long long score = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int val = curr.first;
            int idx = curr.second;

            if (!marked[idx]) {
                score += val;
                marked[idx] = true;

                if (idx - 1 >= 0) {
                    marked[idx - 1] = true;
                }
                if (idx + 1 < n) {
                    marked[idx + 1] = true;
                }
            }
        }

        return score;
    }
};

/*
EXPLANATION OF THE APPROACH:

1. Tracking Smallest and Index Ties:
Since we need to constantly find the absolute smallest unmarked number, and pick the one with the smaller index if there's a tie, a Min-Heap (priority_queue) fits perfectly. In C++, pairs are sorted by their first element by default. If the first elements match, it automatically falls back to comparing the second elements. So pushing {value, index} handles the tie-breaking rule completely free of charge.

2. Lazy Deletion using a Visited Array:
Instead of trying to dynamically erase elements from our heap or modify the original array (which messes up adjacencies and indices), we maintain a simple boolean tracking vector named `marked`. When we pop the minimum element, we quickly check if it has already been swept up by a neighbor. If it is marked, we just ignore it and pop the next one.

3. Marking Neighbors Safely:
If the popped element is unmarked, we add its value to our running `score` variable. Then, we mark the element itself, its left neighbor (idx - 1), and its right neighbor (idx + 1). We use safe boundary checks (`>= 0` and `< n`) to make sure we don't accidentally step out of the vector's memory boundaries.

4. Avoiding Integer Overflow:
The return type expected is a `long long`. This is because summing up large integer elements multiple times can quickly overflow a standard 32-bit `int`. Making `score` a 64-bit integer prevents any silent overflow bugs during accumulation.
*/