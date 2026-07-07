class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //by hashing we are doing it. and then we will do it by two pointer
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]=i;
        }   
        for(int i=0;i<nums.size();i++){
            if(mpp.find(target-nums[i])!=mpp.end()){
                if(mpp[target-nums[i]]!=i)return {mpp[target-nums[i]],i};
            }
        }
        return {-1,-1};
    }
};