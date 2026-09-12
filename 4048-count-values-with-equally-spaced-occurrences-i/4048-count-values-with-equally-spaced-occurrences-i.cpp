class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int,vector<int>>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        int cnt = 0;
        for(auto it: mpp){
           if(it.second.size()==3){
               int a = it.second[0];
               int b = it.second[1];
               int c = it.second[2];
               if(b-a == c-b){
                   cnt++;
               }
           } 
        }
        return cnt;
    }
};