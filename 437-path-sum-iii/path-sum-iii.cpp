#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixCounts;
        // Base case: One way to get a sum of 0 (using no nodes)
        prefixCounts[0] = 1; 
        
        return dfs(root, targetSum, 0, prefixCounts);
    }
    
private:
    int dfs(TreeNode* node, int targetSum, long long currentSum, unordered_map<long long, int>& prefixCounts) {
        if (!node) return 0;
        
        currentSum += node->val;
        
        // Number of valid paths ending at this node
        long long targetPrefix = currentSum - targetSum;
        int numPathsToCurr = prefixCounts.count(targetPrefix) ? prefixCounts[targetPrefix] : 0;
        
        // Add current sum to map to allow descendants to use it
        prefixCounts[currentSum]++;
        
        // Explore children
        int res = numPathsToCurr + 
                  dfs(node->left, targetSum, currentSum, prefixCounts) + 
                  dfs(node->right, targetSum, currentSum, prefixCounts);
        
        // Backtrack: Remove the current node's sum as we move back up the tree
        prefixCounts[currentSum]--;
        
        return res;
    }
};