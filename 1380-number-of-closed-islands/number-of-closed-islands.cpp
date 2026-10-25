#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 1) {
            return;
        }
        
        grid[r][c] = 1;
        
        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int r = 0; r < rows; ++r) {
            if (grid[r][0] == 0) dfs(r, 0, grid);
            if (grid[r][cols - 1] == 0) dfs(r, cols - 1, grid);
        }
        for (int c = 0; c < cols; ++c) {
            if (grid[0][c] == 0) dfs(0, c, grid);
            if (grid[rows - 1][c] == 0) dfs(rows - 1, c, grid);
        }
        
        int closed_islands = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    closed_islands++;
                    dfs(r, c, grid);
                }
            }
        }
        
        return closed_islands;
    }
};