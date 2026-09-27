class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        while(!mpp.empty()){
            vector<int>vect;
            for(auto it: mpp){
                ans.push_back(it.first);
                int x = it.first;
                mpp[x]--;
                if(mpp[x]==0) vect.push_back(x);
            }
            for(auto it: vect){
                mpp.erase(it);
            }
        }
        return ans;
    }
};