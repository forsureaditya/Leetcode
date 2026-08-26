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
    void dfs(TreeNode* root,vector<int>&ans,vector<vector<int>>&fans,int currentcnt,int targetSum){
        
        if(root==NULL){
            if(currentcnt==targetSum){
                fans.push_back(ans);
                return;
            }
            else{
                return;
            }
        }
        if(root->left==NULL && root->right==NULL){
            if(currentcnt==targetSum){
                fans.push_back(ans);
                return;
            }
            else{
                return;
            }
        }
        if(root->left)ans.push_back(root->left->val);
        if(root->left)dfs(root->left,ans,fans,currentcnt+root->left->val,targetSum);
        if(root->left)ans.pop_back();
        if(root->right)ans.push_back(root->right->val);
        if(root->right)dfs(root->right,ans,fans,currentcnt+root->right->val,targetSum);
        if(root->right)ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>ans;
        if(root)ans.push_back(root->val);
        vector<vector<int>>fans;
        if(root)dfs(root,ans,fans,root->val,targetSum);
        return fans;
    }
};