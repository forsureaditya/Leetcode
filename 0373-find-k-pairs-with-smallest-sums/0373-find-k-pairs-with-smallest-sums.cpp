class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>>pq; // max_heap
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                int sum = nums1[i]+nums2[j];
                if(pq.size()<k){
                pq.push({sum,nums1[i],nums2[j]});
                }
                else{
                    if(pq.top()[0]>sum){
                    pq.pop();
                    pq.push({sum,nums1[i],nums2[j]});
                }
                else{
                    break;
                }
                }
            }
        }
            vector<vector<int>>ans;
            while(!pq.empty()){
                ans.push_back({pq.top()[1],pq.top()[2]});
                pq.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
    }
};