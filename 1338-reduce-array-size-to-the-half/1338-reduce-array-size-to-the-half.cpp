class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mpp;
        for(auto it: arr){
            mpp[it]++;
        }
        vector<pair<int,int>>vect;
        for(auto it: mpp){
            vect.push_back({it.second,it.first});
        }
        sort(vect.begin(),vect.end());
        int sum = 0;
        int i=vect.size()-1;
        int cnt = 0;
        while((arr.size()-sum)>arr.size()/2){
            sum+=vect[i].first;
            i--;
            cnt++;
        }
        return cnt;
    }
};