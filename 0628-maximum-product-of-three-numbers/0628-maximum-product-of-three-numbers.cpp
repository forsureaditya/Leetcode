class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size()-1;
        if(nums[n]<0){
            return nums[n]*nums[n-1]*nums[n-2];
        }
        else{
            if(nums[0]*nums[1]>nums[n]*nums[n-1]){
                return nums[0]*nums[n]*nums[1];
            }
            else if(nums[0]*nums[1]*nums[n]>nums[n]*nums[n-1]*nums[n-2]){
                return nums[0]*nums[n]*nums[1];
            }
            else{
                return nums[n]*nums[n-1]*nums[n-2];
            }
        }

    }
};