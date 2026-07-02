// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n = s.length();
//         vector<vector<int>> dp(n, vector<int>(n, 0));

//         for (int i = 0; i < n; i++) {
//             dp[i][i] = 1;
//         }

//         int maxlength = 1;
//         int se = 0;
//         int si = 0;

//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 if (s[i] == s[j]) {
//                     if (i - j >= 2) {
//                         if (dp[i - 1][j + 1] >= 1) {
//                             dp[i][j] = i - j + 1;
//                             if (dp[i][j] > maxlength) {
//                                 maxlength = dp[i][j];
//                                 si = j;
//                                 se = i;
//                             }
//                         } else {
//                             dp[i][j] = 0;
//                         }
//                     } else {
//                         dp[i][j] = 2;
//                         if (dp[i][j] > maxlength) {
//                             maxlength = dp[i][j];
//                             si = j;
//                             se = i;
//                         }
//                     }
//                 }
//             }
//         }

//         string result = s.substr(si, se - si + 1);    
//         return result;
//     }
// };


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";

        // 1D DP table: dp[j] indicates if substring from current i to j is a palindrome
        vector<bool> dp(n, false);
        
        int max_len = 1;
        int start_idx = 0;

        // Loop backwards through starting positions
        for (int i = n - 1; i >= 0; i--) {
            // Loop backwards through ending positions to utilize old row values safely
            for (int j = n - 1; j >= i; j--) {
                if (s[i] == s[j]) {
                    // Base case: length 1 or 2 substrings, or check the inner substring state
                    if (j - i < 2 || dp[j - 1]) {
                        dp[j] = true;
                        
                        // Track the maximum length and starting pointer
                        if (j - i + 1 > max_len) {
                            max_len = j - i + 1;
                            start_idx = i;
                        }
                    } else {
                        dp[j] = false;
                    }
                } else {
                    dp[j] = false;
                }
            }
        }

        return s.substr(start_idx, max_len);
    }
};

