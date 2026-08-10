/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* func(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root == NULL) return NULL;
        if(root == p || root == q) return root;
        TreeNode* ans1 = func(root->left,p,q);
        TreeNode* ans2 = func(root->right,p,q);
        if(ans1 && ans2) return root;
        if(ans1==NULL && ans2!=NULL) return ans2;
        if(ans2==NULL && ans1!=NULL) return ans1; 
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return func(root,p,q);
    }
};