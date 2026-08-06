class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      unordered_map<int,int>mpp;
      int i=0;
      int sum = 0;
      mpp[0]++;
      int cnt = 0;
      while(i<nums.size()){
        sum+=nums[i];
        int diff = sum - goal;
        if(mpp.find(diff)!=mpp.end()){
            cnt+=mpp[diff];
        }
        
        mpp[sum]++;
        i++;
      }
      return cnt;
    }
};