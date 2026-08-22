class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>ans;
        for(int i=0;i<capacity.size();i++){
            ans.push_back(capacity[i]-rocks[i]);
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            if(ans[i]>additionalRocks){
                ans[i] = ans[i]-additionalRocks;
            }
            else{
                additionalRocks = additionalRocks - ans[i];
                ans[i] = 0;
            }
        }
        int cnt = 0;
        for(auto it: ans){
            if(it==0) cnt++;
        }
        return cnt;
    }
};