class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>p;
        for(int i=0;i<plantTime.size();i++){
            p.push_back({growTime[i],plantTime[i]});
        }
        sort(p.begin(),p.end());
        reverse(p.begin(),p.end());
        int sum = -1;
        int ans = 0;
        for(int i=0;i<p.size();i++){
            sum+=p[i].second;
            ans = max(ans,sum+p[i].first+1);
        }
        return ans;
    }
};