class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> present(26, 0);
        stack<char> st;

        for (char c : s) {
            freq[c - 'a']--;

            // If already in the stack, skip it
            if (present[c - 'a']) {
                continue;
            }

            while (!st.empty() &&
                   st.top() > c &&
                   freq[st.top() - 'a'] > 0) {

                present[st.top() - 'a'] = 0;
                st.pop();
            }

            st.push(c);
            present[c - 'a'] = 1;
        }

        string result;

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};