#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 10) return {};

        unordered_map<char, int> dnaMap = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        
        unordered_set<int> seen;
        unordered_set<string> repeated; 
        
        int currentHash = 0;
        
        for (int i = 0; i < 9; i++) {
            currentHash = (currentHash << 2) | dnaMap[s[i]];
        }
        
        for (int i = 9; i < s.length(); i++) {
            currentHash = ((currentHash << 2) | dnaMap[s[i]]) & 0xFFFFF;
            
            if (seen.count(currentHash)) {
                repeated.insert(s.substr(i - 9, 10));
            } else {
                seen.insert(currentHash);
            }
        }
        
        return vector<string>(repeated.begin(), repeated.end());
    }
};