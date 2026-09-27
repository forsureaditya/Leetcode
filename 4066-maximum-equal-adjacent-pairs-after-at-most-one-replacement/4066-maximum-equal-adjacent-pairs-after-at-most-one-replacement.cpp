class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int,int>,int>mpp;
        vector<pair<int,int>>collect;
        for(int i=0;i<nums.size()-1;i++){
            mpp[{nums[i],nums[i+1]}]++;
            collect.push_back({nums[i],nums[i+1]});
        }
        int ans = 0;
        for(auto it: collect){
            if(it.first == it.second) ans++;
        }
        map<pair<int,int>,int>mpp2;
        for(int i=0;i<collect.size();i++){
            if(collect[i].first == collect[i].second) continue;
            if(mpp.find({collect[i].first,
                         collect[i].second})!=mpp.end()){
                if(mpp2.find({collect[i].second,collect[i].first})
                    != mpp2.end()){
                    mpp2[{collect[i].second,collect[i].first}]++;
                    }
                else{
                    mpp2[{collect[i].first,collect[i].second}]++;
                }
            }
        }
        int max = 0;
        for(auto it:mpp2){
            if(max<it.second) max = it.second;
        }
        return ans+max;
    }
};