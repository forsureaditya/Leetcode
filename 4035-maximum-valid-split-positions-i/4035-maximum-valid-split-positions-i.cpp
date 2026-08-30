class Solution {
public:
    int func(vector<int>nums , int i){
        if(i!=-1){
            nums.erase(nums.begin()+i);
        }
        int cnt = 0;
        vector<int>prefix(nums.size());
        vector<int>suffix(nums.size());
        prefix[0] = nums[0];
        suffix[nums.size()-1] = nums[nums.size()-1];
        for(int i=1;i<nums.size();i++){
            prefix[i] = __gcd(nums[i],prefix[i-1]);
        }
        for(int i=nums.size()-2;i>=0;i--){
            suffix[i] = __gcd(nums[i],suffix[i+1]);
        }
        for(int i=0;i<nums.size()-1;i++){
            if(prefix[i]==suffix[i+1]){
                cnt++;
            }
        }
        return cnt;
    }
    int maxValidSplits(vector<int>& nums) {
        int ans = func(nums,-1);// im trying to calculate number of splits with no element deleted.
        for(int i=0;i<nums.size();i++){
            ans = max(ans,func(nums,i));// im trying to calculate the number of splits with one 
                                        // one element deleted
        }
        return ans;
    }
};