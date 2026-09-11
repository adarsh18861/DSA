/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans = 0;


    pair<int,int> solve(TreeNode* root ){

        if(root == NULL) return {0,0};

         auto  [leftsum,leftcount] = solve(root->left);
         auto  [rightsum,rightcount] = solve(root->right);

         int totalsum = leftsum + rightsum +root->val;
         int totalcount = leftcount + rightcount +1;

         if(root->val == totalsum/totalcount) ans++;


         return {totalsum,totalcount};


    }
public:
    int averageOfSubtree(TreeNode* root) {

        solve(root); 

        return ans;
    }
};