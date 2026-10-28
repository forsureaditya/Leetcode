class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int>mpp;
       int sum = 0;
       mpp[0]++;
       int cnt = 0;
       for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        int diff = sum-k;
        if(mpp.find(diff)!=mpp.end()){
            cnt+=mpp[diff];
        }
        mpp[sum]++;
       } 
       return cnt;
    }
};