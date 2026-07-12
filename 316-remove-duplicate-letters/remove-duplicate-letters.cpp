#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<bool> visited(26, false);
        stack<char> st;

        for (char c : s) {
            freq[c - 'a']--;

            if (visited[c - 'a']) {
                continue;
            }

            while (!st.empty() && c < st.top() && freq[st.top() - 'a'] > 0) {
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            visited[c - 'a'] = true;
        }

        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result; 
    }
};