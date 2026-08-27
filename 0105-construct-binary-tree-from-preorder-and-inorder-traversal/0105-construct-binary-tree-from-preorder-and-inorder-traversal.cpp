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
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0) return nullptr;  
        if(preorder.size()==1 && inorder.size()==1){
            TreeNode* temp = new TreeNode(preorder[0]);
            return temp;
        }
        TreeNode* head = new TreeNode(preorder[0]);
        int i=0;
        while(inorder[i]!=preorder[0]){
            i++;
        }
        int cntlft = i;
        vector<int>lftpreorder;
        for(int j=1;j<=i;j++) lftpreorder.push_back(preorder[j]);
        vector<int>lftinorder;
        for(int j=0;j<i;j++) lftinorder.push_back(inorder[j]);
        head->left = buildTree(lftpreorder,lftinorder);
        vector<int>rgtpreorder;
        for(int j=i+1;j<preorder.size();j++) rgtpreorder.push_back(preorder[j]);
        vector<int>rgtinorder;
        for(int j=i+1;j<inorder.size();j++) rgtinorder.push_back(inorder[j]);
        head->right = buildTree(rgtpreorder,rgtinorder);
        return head;
    }
};