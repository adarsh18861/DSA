class Solution {
    int memo[100][100][200]; // m, n <= 100, max path length m+n <= 200

    bool solve(vector<vector<char>>& grid, int i, int j, int bal, int m, int n) {
        if (i >= m || j >= n) return false;

        if (grid[i][j] == '(') {
            bal++;
        } else {
            bal--;
        }

        if (bal < 0) return false;

        if (i == m - 1 && j == n - 1) {
            return bal == 0;
        }

        if (memo[i][j][bal] != -1) {
            return memo[i][j][bal];
        }

        bool res = solve(grid, i, j + 1, bal, m, n) || solve(grid, i + 1, j, bal, m, n);

        return memo[i][j][bal] = res;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        memset(memo, -1, sizeof(memo));

        return solve(grid, 0, 0, 0, m, n);
    }
};