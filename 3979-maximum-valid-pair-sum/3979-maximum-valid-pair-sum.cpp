class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int i = nums.size()-1-k;
        int j = nums.size()-1;
        int maxi = INT_MIN;
        int ans = 0;
        while(i>=0){
            maxi = max(maxi,nums[j]);
            ans = max(maxi+nums[i],ans);
            i--;
            j--;
        }
        return ans;
    }
};