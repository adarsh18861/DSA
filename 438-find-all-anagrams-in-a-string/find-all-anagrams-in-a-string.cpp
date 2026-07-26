#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), m = p.length();
        vector<int> result;
        if (m > n) return result;
        
        vector<int> p_freq(26, 0), window_freq(26, 0);
        for (int i = 0; i < m; i++) {
            p_freq[p[i] - 'a']++;
            window_freq[s[i] - 'a']++;
        }
        
        if (p_freq == window_freq) {
            result.push_back(0);
        }
        
        for (int i = m; i < n; i++) {
            window_freq[s[i] - 'a']++;
            window_freq[s[i - m] - 'a']--;
            
            if (p_freq == window_freq) {
                result.push_back(i - m + 1);
            }
        }
        
        return result;
    }
};