class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) { 
        vector<pair<int,int>>pr; //1st->nums2 2nd->nums1
    for(int i=0;i<nums1.size();i++){ 
        pr.push_back({nums2[i],nums1[i]}); 
        } 
        sort(pr.begin(),pr.end());
            long long ans = 0;
            long long sum = 0;
            priority_queue<int,vector<int>,greater<>>pq;
            for(int i=pr.size()-1;i>=0;i--){
                pq.push(pr[i].second);
                sum+=pr[i].second;
                while(pq.size()>k){
                sum-=pq.top();
                pq.pop();
                }
                if(pq.size()!=k) continue;
                ans = max(ans,sum*pr[i].first*1LL);
            }
         return ans; 
    }
};
// doo din lag gaye bhai isko solve karne mein 
// kitna chutiya question hai socho.