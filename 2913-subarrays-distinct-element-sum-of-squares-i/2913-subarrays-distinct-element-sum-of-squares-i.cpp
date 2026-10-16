class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                unordered_map<int,int>mpp;
                for(int k=i;k<=j;k++){
                    mpp[nums[k]]++;
                }
                ans+=mpp.size()*mpp.size();
            }
        }
        return ans;
    }
};