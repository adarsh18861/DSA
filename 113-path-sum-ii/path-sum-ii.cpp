#include <bits/stdc++.h>
using namespace std;

class Solution {
    void backtrack(TreeNode* node, int targetSum, vector<int>& currentPath, vector<vector<int>>& result) {
        if (!node) return;
        
        // Add node to the current path and subtract its value from target
        currentPath.push_back(node->val);
        targetSum -= node->val;
        
        // If it's a leaf node and target sum is met, add path to result
        if (!node->left && !node->right && targetSum == 0) {
            result.push_back(currentPath);
        } else {
            // Otherwise, keep exploring down
            backtrack(node->left, targetSum, currentPath, result);
            backtrack(node->right, targetSum, currentPath, result);
        }
        
        // Backtracking: Remove the current node before going back up the tree
        currentPath.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> currentPath; // Single path maintained throughout traversal
        
        backtrack(root, targetSum, currentPath, result);
        
        return result;
    }
};