class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> idx;
        for(int i=0;i<s.size();i++){
            if(s[i]==c){
                idx.push_back(i);
            }
        }
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            if(s[i]==c){
                ans.push_back(0);
            }
            else{
                int mini = INT_MAX;
                for(auto it:idx){
                    mini = min(mini,abs(it-i));
                }
                ans.push_back(mini);
            }
        }
        return ans;
    }
};