class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        map<int,int>mpp;
        for(int i=lower;i<=upper;i++){
            mpp[i]++;
        }
        for(int i=0;i<nums.size();i++){
          
           if(mpp.find(nums[i])!=mpp.end())mpp.erase(nums[i]);
        }
        vector<int>collect;
        for(auto it: mpp){
            collect.push_back(it.first);
        }
        vector<vector<int>>ans;
        if(collect.size()==0) return {};
        int lowerlmt = collect[0];
        
        for(int i=1;i<collect.size();i++){
           while(i<collect.size() && collect[i] == collect[i-1]+1){
               i++;
           } 
            ans.push_back({lowerlmt,collect[i-1]});
            if(i<collect.size())lowerlmt = collect[i];
        }
        if(lowerlmt==collect[collect.size()-1]){
            ans.push_back({lowerlmt,lowerlmt});
        }
        return ans;
    }
};