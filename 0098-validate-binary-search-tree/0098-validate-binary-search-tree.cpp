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
    void dfs(TreeNode* root,vector<int>&vect){
        if(root==NULL) return;
        dfs(root->left,vect);
        vect.push_back(root->val);
        dfs(root->right,vect);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>vect;
        dfs(root,vect);
        unordered_map<int,int>mpp;
        for(auto it: vect) mpp[it]++;
        for(auto it: mpp){
            if(it.second>1) return false;
        }
        if(is_sorted(vect.begin(),vect.end())) return true;
        return false;
    }
};