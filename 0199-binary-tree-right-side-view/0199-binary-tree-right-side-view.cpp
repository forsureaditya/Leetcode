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
    void dfs(TreeNode* root,vector<vector<int>>&ans,int level){
        if(root==NULL) return;
        if(level == ans.size())          
        ans.push_back({});    
        ans[level].push_back(root->val);
        if(root->left)dfs(root->left,ans,level+1);
        if(root->right)dfs(root->right,ans,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>>ans;
        dfs(root,ans,0);
        vector<int>fans;
        for(auto it: ans){
            fans.push_back(it[it.size()-1]);
        }
        return fans;
    }
};