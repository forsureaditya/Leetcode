class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long ans = 0;
        for(int i=0;i<intervals.size();i++){
            if(pq.empty()){
                pq.push(intervals[i][1]);
            }
            else{
                while(!pq.empty() && pq.top()<intervals[i][0]){
                    pq.pop();
                }
                ans+=pq.size();
                pq.push(intervals[i][1]);
            }
        }
        return ans;
    }
};