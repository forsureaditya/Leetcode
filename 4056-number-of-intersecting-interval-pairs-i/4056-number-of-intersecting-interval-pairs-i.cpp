class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        for(int i=0;i<intervals.size();i++){  
            for(int j=i+1;j<intervals.size();j++){
            int a = intervals[i][0];
            int b = intervals[i][1];
            int c = intervals[j][0];
            int d = intervals[j][1];
            if((a<=c && c<=b) ||(a>=c && a<=d) || (b>c && b<=d) || (b>d && a<=d)){
                ans++;
            }

        }
        }
        return ans;
    }
};