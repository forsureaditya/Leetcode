class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mxi = nums[0];
        vector<int>prefixGcd(nums.size());
        for(int i=0;i<nums.size();i++){
            mxi = max(mxi,nums[i]);
            prefixGcd[i]=__gcd(mxi,nums[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int i=0;
        int j=prefixGcd.size()-1;
        long long sum = 0;
        while(i<j){
            sum+=__gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};