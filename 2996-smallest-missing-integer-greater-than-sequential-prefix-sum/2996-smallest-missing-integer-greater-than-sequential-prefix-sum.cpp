class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++) mpp[nums[i]]++;
        int maxsum = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1) maxsum+=nums[i];
            else break;
        }
        if(mpp.find(maxsum)==mpp.end()) return maxsum;
        while(mpp.find(maxsum)!=mpp.end()){
            maxsum++;
        }
        return maxsum;
    }
};