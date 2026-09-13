class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int right = 0;
        int left = 0;
        double sum = 0;
        double ans = INT_MIN;
        while(right<nums.size()){
            sum+=nums[right];
            if(right-left+1>k){
                sum-=nums[left];
                left++;
            }
            if(right-left+1==k){
                double ans2 = sum/(float)k;
                ans = max(ans,ans2);
            }
            right++;
        }
        return ans;
    }
};