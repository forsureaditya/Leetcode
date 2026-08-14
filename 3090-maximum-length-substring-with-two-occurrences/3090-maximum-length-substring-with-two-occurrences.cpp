class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0;
        int r = 0;
        int maxfreq = 0;
        char mchar = s[0];
        int cnt = 0;
        unordered_map<char,int>mpp;
        while(r<s.size()){
            mpp[s[r]]++;
            if(maxfreq<mpp[s[r]]){
                maxfreq = mpp[s[r]];
                mchar = s[r];
            }
            if(maxfreq>2){
                while(mpp[mchar]>2){
                    mpp[s[l]]--;
                    l++;
                }
            }
            maxfreq = mpp[mchar];
            cnt = max(cnt,r-l+1);
            r++;
        }
        return cnt;
    }
};