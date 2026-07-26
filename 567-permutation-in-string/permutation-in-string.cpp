#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2) return false;
        
        vector<int> s1_freq(26, 0), window_freq(26, 0);
        for (int i = 0; i < n1; i++) {
            s1_freq[s1[i] - 'a']++;
            window_freq[s2[i] - 'a']++;
        }
        
        if (s1_freq == window_freq) return true;
        
        for (int i = n1; i < n2; i++) {
            window_freq[s2[i] - 'a']++;
            window_freq[s2[i - n1] - 'a']--;
            
            if (s1_freq == window_freq) return true;
        }
        return false;
    }
};