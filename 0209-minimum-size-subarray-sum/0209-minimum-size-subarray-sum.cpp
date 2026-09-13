class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int right = 0;
        int left = 0;
        int sum = 0;
        int ans = INT_MAX;
        while(right<nums.size()){
            sum+=nums[right];
            while(sum-nums[left]>=target){
                sum-=nums[left];
                left++;
            }
            if(sum>=target){
                ans = min(ans,right-left+1);
            }
            right++;
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};