class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mpp;
        int l = 0;
        int r = 0;
        int maxfreq = 0;
        int maxlen  = 0;
        while(r<s.size()){
            mpp[s[r]]++;
            maxfreq = max(maxfreq,mpp[s[r]]);
            int change = r-l+1 - maxfreq ;
            if(change<=k){
                // no problem at all.
                maxlen = max(maxlen, r-l+1);
            }
            else{
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
            r++;
        }
        return maxlen;
    }
};