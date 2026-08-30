class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            while(j<nums.size() && nums[i]==nums[j]) j++;
            if(j-i == mpp[nums[i]]){
                cnt++;
            }
            i = j;
            i--;
        }
        return cnt;
    }
};