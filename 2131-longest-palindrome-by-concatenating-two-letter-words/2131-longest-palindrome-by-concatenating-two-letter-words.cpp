class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mpp;
        for(int i=0;i<words.size();i++){
            mpp[words[i]]++;
        }
        int len = 0;
        int single = 0;
        for(int i=0;i<words.size();i++){
            if(words[i][0]!=words[i][1]) continue;
            else{
                if(mpp[words[i]]>=2){
                len+=2;
                mpp[words[i]]-=2;
                if(mpp[words[i]]==0) mpp.erase(words[i]);
                }
                else if(mpp[words[i]]==1){
                    if(single ==0){
                    single++;
                    }
                    else continue;
                }
            }
        }
        len+=single;
        for(int i=0;i<words.size();i++){
            reverse(words[i].begin(),words[i].end());
            if(words[i][0]==words[i][1]){
                continue;
            }
            else if(mpp.find(words[i])!=mpp.end()){
                len++;
                mpp[words[i]]--;
                if(mpp[words[i]]==0) mpp.erase(words[i]);
            }
        }
        return len*2;
    }
};