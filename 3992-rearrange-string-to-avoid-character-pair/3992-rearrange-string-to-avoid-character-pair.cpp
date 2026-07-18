class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i]==y) ans+=y;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]==x) ans+=x;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!=y && s[i]!=x) ans+=s[i];
        }
        return ans;
    }
};