#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int q = queries.size();
        vector<int> ans(q, -1);
        vector<vector<pair<int, int>>> store(n);

        for (int i = 0; i < q; ++i) {
            int a = queries[i][0];
            int b = queries[i][1];
            if (a > b) swap(a, b);
            
            if (a == b || heights[a] < heights[b]) {
                ans[i] = b;
            } else {
                store[b].push_back({heights[a], i});
            }
        }

        vector<int> st;
        for (int i = n - 1; i >= 0; --i) {
            for (auto& q_pair : store[i]) {
                int target = q_pair.first;
                int q_idx = q_pair.second;
                
                int low = 0, high = (int)st.size() - 1;
                int res = -1;
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if (heights[st[mid]] > target) {
                        res = st[mid];
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                ans[q_idx] = res;
            }

            while (!st.empty() && heights[st.back()] <= heights[i]) {
                st.pop_back();
            }
            st.push_back(i);
        }

        return ans;
    }
};