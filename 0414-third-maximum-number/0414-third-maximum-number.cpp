class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int secmax = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=maxi){
                if(secmax == -1) secmax = i;
                if(nums[secmax]<nums[i]){
                    secmax = i;
                }
            }
        }
        if(secmax == -1) return maxi;
        int thirdmax = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=nums[secmax] && nums[i]!=maxi){
                if(thirdmax == -1) thirdmax = i;
                if(nums[thirdmax]<nums[i]){
                    thirdmax = i;
                }
            }
        }
        if(thirdmax == -1) return maxi;
        return nums[thirdmax];
    }
};