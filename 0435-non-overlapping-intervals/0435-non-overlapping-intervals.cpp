class Solution {
public:
    static bool comp(vector<int>a , vector<int> b){
    return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        sort(a.begin(),a.end(),comp);
        long long lst = INT_MIN;
        long long cnt = 0;
        for(auto it : a){
            if(lst == INT_MIN){
                cnt++;
                lst = it[1];
            }
            else if( lst <= it[0]){
                cnt++;
                lst = it[1];
            }
        }
        return a.size() - cnt;
    }
};