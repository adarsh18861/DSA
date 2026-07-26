#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        // 1. Compute 1D prefix sum for each row independently
        for (int i = 0; i < r; i++) {
            for (int j = 1; j < c; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        
        int count = 0;
        
        // 2. Fix the left and right column boundaries
        for (int c1 = 0; c1 < c; c1++) {
            for (int c2 = c1; c2 < c; c2++) {
                
                unordered_map<int, int> prefCount;
                prefCount[0] = 1; // Base case: submatrix starting from the very first row
                int currentSum = 0;
                
                // 3. Traverse row by row within this column band
                for (int i = 0; i < r; i++) {
                    // Extract the sum of the current row between c1 and c2
                    int rowSum = matrix[i][c2] - (c1 > 0 ? matrix[i][c1 - 1] : 0);
                    currentSum += rowSum;
                    
                    // Apply the 1D Prefix Sum + Hash Map trick
                    if (prefCount.count(currentSum - target)) {
                        count += prefCount[currentSum - target];
                    }
                    
                    // Record the current prefix sum
                    prefCount[currentSum]++;
                }
            }
        }
        
        return count;
    }
};