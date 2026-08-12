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
     void func(TreeNode* root,int k,vector<vector<int>>&ans){
        if(root == NULL) return;
        if(ans.size() == k) ans.push_back({});  
        ans[k].push_back(root->val);
        func(root->left,k+1,ans);
        func(root->right,k+1,ans);

    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        int k = 0;
        func(root,k,ans);
        for(int i=0;i<ans.size();i++){
            if(i%2!=0) reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};