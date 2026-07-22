#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int maxVal = -1e9;
        // deque stores pairs of {y_i - x_i, x_i}
        deque<pair<int, int>> dq;

        for (const auto& point : points) {
            int xj = point[0];
            int yj = point[1];

            // Step 1: Evict points outside the valid x-range [xj - k, xj]
            while (!dq.empty() && xj - dq.front().second > k) {
                dq.pop_front();
            }

            // Step 2: Calculate maximum equation value using the front element
            if (!dq.empty()) {
                maxVal = max(maxVal, xj + yj + dq.front().first);
            }

            // Step 3: Maintain monotonic decreasing order of (y_i - x_i)
            int currentDiff = yj - xj;
            while (!dq.empty() && dq.back().first <= currentDiff) {
                dq.pop_back();
            }

            // Step 4: Add current point's {y_j - x_j, x_j} to the deque
            dq.push_back({currentDiff, xj});
        }

        return maxVal;
    }
};