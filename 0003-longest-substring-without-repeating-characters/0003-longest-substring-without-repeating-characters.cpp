class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int maxcnt = 0;
        unordered_map<char,int>mpp;
        for(int j=0;j<s.size();j++){
            if(mpp.find(s[j])==mpp.end()){
                maxcnt = max(maxcnt,j-i+1);
                mpp[s[j]] = j;
            }
            else{
                i=mpp[s[j]]+1;
                mpp.clear();
                j= i-1;
            }
        }
        return maxcnt;
    }
};