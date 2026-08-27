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
    TreeNode* func(vector<int> & preorder , int s, int e){
        if(s>e){
            return NULL;
        }
        TreeNode* head = new TreeNode(preorder[s]);
        int i=s+1;
        while(i<=e && preorder[i]<preorder[s]){
            i++;
        }
        head->left = func(preorder,s+1,i-1);
        head->right = func(preorder,i,e); 
        return head;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* head = new TreeNode(preorder[0]);
        int i=1;
        while(i<preorder.size() && preorder[i]<preorder[0]){
            i++;
        }
        head->left = func(preorder,1,i-1);
        head->right = func(preorder,i,preorder.size()-1);
        return head;
    }
};