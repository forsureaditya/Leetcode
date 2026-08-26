class Solution {
public:
 void dfs(TreeNode* root,vector<int>&ans,int & cnt,long long currentcnt,long long targetSum){
        if(root==NULL){
            if(currentcnt==targetSum){
                cnt++;
                return;
            }
            else{
                return;
            }
        }
        if(targetSum == currentcnt) {
            cnt++;
           
        }
        if(root->left)ans.push_back(root->left->val);
        if(root->left)dfs(root->left,ans,cnt,currentcnt+root->left->val,targetSum);
        if(root->left)ans.pop_back();
        if(root->right)ans.push_back(root->right->val);
        if(root->right)dfs(root->right,ans,cnt,currentcnt+root->right->val,targetSum);
        if(root->right)ans.pop_back();
    }
    void traversal(TreeNode* root,vector<int> & ans,int & cnt, long long targetSum){
       if(root==NULL) return;
       if(root->left) dfs(root->left,ans,cnt,root->left->val,targetSum);
       if(root->right) dfs(root->right,ans,cnt,root->right->val,targetSum);
       if(root->left)traversal(root->left, ans, cnt, targetSum);   
       if(root->right)traversal(root->right, ans, cnt, targetSum);  
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int>ans;
        if(root)ans.push_back(root->val);
        int cnt = 0;
        if(root)dfs(root,ans,cnt,root->val,targetSum);
        if(root)traversal(root,ans,cnt,targetSum);
        return cnt;
    }
};