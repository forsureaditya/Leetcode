class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& i, vector<int>& ni) {
      
        vector<vector<int>> ans;
        int j = 0;
        while(j<i.size() && i[j][1]<ni[0]){
            ans.push_back(i[j]);
            j++;
        }
        int lower_limit = ni[0];
        int upper_limit = ni[1];
        while(j<i.size() && i[j][0]<=ni[1]){
            lower_limit = min(lower_limit,i[j][0]);
            upper_limit = max(upper_limit,i[j][1]);
            j++;
        }
        ans.push_back({lower_limit,upper_limit});
        while(j<i.size()) {
            ans.push_back(i[j]);
            j++;
        }
        return ans;
    }
};