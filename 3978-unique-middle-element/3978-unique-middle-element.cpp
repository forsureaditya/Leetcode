class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        if(mpp[nums[(n)/2]]==1) return true;
        return false;
    }
};