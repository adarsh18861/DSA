#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        
        vector<int> start(26, -1), end(26, -1);
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - 'a';
            if (start[idx] == -1) {
                start[idx] = i;
            }
            end[idx] = i;
        }

        vector<pair<int, int>> valid_intervals;
        for (int i = 0; i < 26; ++i) {
            if (start[i] == -1) continue;

            int left = start[i];
            int right = end[i];
            bool is_valid = true;

            for (int j = left; j <= right; ++j) {
                int ch_idx = s[j] - 'a';
                if (start[ch_idx] < left) {
                    is_valid = false;
                    break;
                }
                right = max(right, end[ch_idx]);
            }

            if (is_valid) {
                valid_intervals.push_back({left, right});
            }
        }

        sort(valid_intervals.begin(), valid_intervals.end(), 
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });

        vector<string> result;
        int prev_end = -1;
        for (const auto& interval : valid_intervals) {
            if (interval.first > prev_end) {
                result.push_back(s.substr(interval.first, interval.second - interval.first + 1));
                prev_end = interval.second;
            }
        }

        return result;
    }
};