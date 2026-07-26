#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int balancedString(string s) {
        int n = s.length();
        int k = n / 4;
        vector<int> count(128, 0);
        
        for (char c : s) {
            count[c]++;
        }
        
        int ans = n;
        for (int i = 0, j = 0; i < n; i++) {
            count[s[i]]--;
            
            while (j < n && count['Q'] <= k && count['W'] <= k && count['E'] <= k && count['R'] <= k) {
                ans = min(ans, i - j + 1);
                count[s[j]]++;
                j++;
            }
        }
        return ans;
    }
};