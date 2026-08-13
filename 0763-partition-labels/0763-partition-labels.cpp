class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]=i;
        }
        int maxi = mpp[s[0]];
        int prev = -1;
        for(int i=0;i<s.size();i++){
            if(i<=maxi){
                maxi=max(maxi,mpp[s[i]]);
            }
            else{
                ans.push_back(maxi-prev);
                prev = maxi;
                maxi = mpp[s[i]];
            }
        }
        ans.push_back(maxi-prev);
        return ans;
    }
};