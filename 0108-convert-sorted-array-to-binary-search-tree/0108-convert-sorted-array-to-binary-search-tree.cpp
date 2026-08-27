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
    TreeNode* func(vector<int>&nums,int s,int e){
        if(s>e){
            return NULL;
        }
        if(s==e){
            return new TreeNode(nums[s]);
        }
        int mid = (e-s)/2 + s;
        TreeNode* head = new TreeNode(nums[mid]);
        head->left = func(nums,s,mid-1);
        head->right = func(nums,mid+1,e);
        return head;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int s = 0;
        int e = nums.size()-1;
        int mid = (e-s)/2 + s;
        TreeNode* head = new TreeNode(nums[mid]);
        head->left = func(nums,0,mid-1);
        head->right = func(nums,mid+1,nums.size()-1);
        return head;
    }
};