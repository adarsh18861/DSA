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
public:
    TreeNode* deleteHelper(TreeNode* root, vector<int>& to_delete,unordered_set<int> st,vector<TreeNode*>& result){
         if(root == NULL){
            return NULL;
         }

         root->left = deleteHelper(root->left,to_delete,st,result);
         root->right = deleteHelper(root->right,to_delete,st,result);

         if(st.find(root->val) != st.end()){
            if(root->left != NULL) result.push_back(root->left);
            if(root->right != NULL) result.push_back(root->right);
            return NULL;
         }

         else{
            return root;
         }

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        unordered_set<int> st;
        vector<TreeNode*> result;

        for(int num: to_delete){
            st.insert(num);
        }

        deleteHelper(root,to_delete,st,result);
        if(st.find(root->val) == st.end()){
            result.push_back(root);
         }

         return result;

    }
};