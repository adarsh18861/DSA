class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int K = 1024;                       // set >= 2^bits of max value
        vector<vector<bitset<K>>> reach(m, vector<bitset<K>>(n));

        reach[0][0][grid[0][0]] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                bitset<K> prev;
                if (i > 0) prev |= reach[i-1][j];
                if (j > 0) prev |= reach[i][j-1];
                for (int x = 0; x < K; x++)
                    if (prev[x]) reach[i][j][x ^ grid[i][j]] = 1;
            }
        }

        for (int x = 0; x < K; x++)
            if (reach[m-1][n-1][x]) return x;
        return -1;
    }
};