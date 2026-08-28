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
    TreeNode* func(TreeNode* root){
        if(root==NULL) return NULL;
        root = root->left;
        while(root->right!=NULL){
            root=root->right;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key){
            //case 1:
            if(root->left == NULL && root->right == NULL){
                return NULL;
            }
            //case 3:
            else if(root->left && root->right){
                TreeNode* pre = func(root);
                root->val = pre->val;
                root->left = deleteNode(root->left,pre->val);
            }
            //case 2:
            else{
                if(root->left){
                    return root->left;
                }
                else{
                    return root->right;
                }
            }
        }
        else if(root->val < key){
            root->right = deleteNode(root->right,key);
        }
        else{
            root->left = deleteNode(root->left,key);
        }
        return root;
    }
};