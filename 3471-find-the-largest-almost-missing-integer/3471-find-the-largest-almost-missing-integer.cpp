class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            vector<int>temp;
            int j = i;
            int cnt = 0;
            while(j<nums.size() && cnt<k){
                temp.push_back(nums[j]);
                cnt++;
                j++;
            }
            if(cnt == k) ans.push_back(temp);
        }
        for(auto it: ans){
            unordered_map<int,int>mpp2;
            for(auto i: it){
                if(mpp2.find(i)!=mpp.end()){
                    continue;
                }
                else{
                    mpp[i]++;
                    mpp2[i]++;
                }
            }
        }
        int fans = -1;
        for(auto it: mpp){
            if(it.second == 1) fans = max(fans,it.first);
        }
        return fans;
    }
};