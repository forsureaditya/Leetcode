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
    void inorder(TreeNode* root, vector<int> & vect){
        if(root==NULL) return;
        inorder(root->left,vect);
        vect.push_back(root->val);
        inorder(root->right,vect);
    }
    void dfs(TreeNode* root,unordered_map<int,int>mpp){
        if(root == NULL) return;
        root->val = mpp[root->val];
        dfs(root->left,mpp);
        dfs(root->right,mpp);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>vect;
        inorder(root,vect);
        unordered_map<int,int>mpp;
        int sum = 0;
        for(int i=vect.size()-1;i>=0;i--){
            sum+=vect[i];
            mpp[vect[i]] = sum;
        }
        dfs(root,mpp);
        return root;
    }
};