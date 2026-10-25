class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        vector<vector<int>> collect(nums.size());
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            while(x){
                collect[i].push_back(x%10);
                x/=10;
            }
        }
        vector<pair<int,int>>p(nums.size());
        for(int i=0;i<collect.size();i++){
            reverse(collect[i].begin(),collect[i].end());
            long long nm = 0;
            for(auto ct: collect[i]){
                nm = nm*10+ct;
            }
            sort(collect[i].begin(),collect[i].end());
            reverse(collect[i].begin(),collect[i].end());
            long long pm = 0;
            for(auto it: collect[i]){
                pm = pm*10+it;
            }
            p[i] = {pm,nm};
        }
        
        sort(p.begin(), p.end(), [](auto &a, auto &b){
    return (a.first - a.second) < (b.first - b.second);
});
        int i = p.size()-1;
        long long ans = 0;
        while(i>=0){
          if(p[i].first>p[i].second && k){
              ans+=p[i].first;
              k--;
          } 
          else ans+=p[i].second;
        
          i--;
        }
        return ans;
    }
};