class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(auto it: s){
            mpp[it]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it: mpp){
            pq.push({it.second,it.first});
        }
        string str = "";
        while(pq.size()){
            int n = pq.top().first;
            while(n){
                str+=pq.top().second;
                n--;
            }
            pq.pop();
        }
        return str;
    }
};