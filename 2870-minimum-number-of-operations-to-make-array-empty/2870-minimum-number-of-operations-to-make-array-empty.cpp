class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int ans = 0;
        for(auto it: mpp){
            if(it.second==1) return -1;
            int val = it.second;
            if(val%3==0){
                ans += it.second/3;
            }
            else if(val%3==1){
                int pdt = it.second/3;
                ans += (pdt-1) + (it.second-3*(pdt-1))/2;
            }
            else{
                ans += it.second/3 + 1;
            }
        }
        return ans;
    }
};