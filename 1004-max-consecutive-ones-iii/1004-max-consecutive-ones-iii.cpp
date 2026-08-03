class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int cnt = 0;
        int maxans = 0;
        while(r<nums.size()){
            if(nums[r]==0){
                cnt++;
            }
            if(cnt<=k){
                maxans = max(maxans,r-l+1);
            }
            else{
                if(nums[l]==0) 
                cnt--;
            
            
            l++;
            }
            r++;
        }
      
        return maxans;
    }
};