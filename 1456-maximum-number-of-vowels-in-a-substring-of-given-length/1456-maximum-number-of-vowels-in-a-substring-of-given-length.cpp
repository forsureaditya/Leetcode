class Solution {
public:
    int maxVowels(string s, int k) {
        int cnt = 0;
        int l = 0;
        int r = 0;
        int cntvowel = 0;
        int ans = 0;
        while(r<s.size()){
            cnt++;
            if(s[r]=='a'||s[r]=='e'||s[r]=='i'||s[r]=='o'||s[r]=='u'){
                cntvowel++;
            }
            if(cnt>k){
                cnt--;
                if(s[l]=='a'||s[l]=='e'||s[l]=='i'||s[l]=='o'||s[l]=='u') cntvowel--;
                l++;
            }
            if(cnt==k){
                ans = max(ans,cntvowel);
            }
            r++;
        }
        return ans;
    }
};