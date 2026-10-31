#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;

        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) {
            return 0;
        }

        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2, 0)));

        dp[0][0][0] = 1;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                long long total_in = (dp[r][c][0] + dp[r][c][1]) % MOD;

                if (total_in == 0) continue;

                if (grid[r][c] == 0) {
                    if (c + 1 < n) {
                        dp[r][c + 1][0] = (dp[r][c + 1][0] + total_in) % MOD;
                    }
                    if (r + 1 < m) {
                        dp[r + 1][c][1] = (dp[r + 1][c][1] + total_in) % MOD;
                    }
                } else {
                    if (dp[r][c][0] > 0 && r + 1 < m) {
                        dp[r + 1][c][1] = (dp[r + 1][c][1] + dp[r][c][0]) % MOD;
                    }
                    if (dp[r][c][1] > 0 && c + 1 < n) {
                        dp[r][c + 1][0] = (dp[r][c + 1][0] + dp[r][c][1]) % MOD;
                    }
                }
            }
        }

        return (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % MOD;
    }
};