class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>a(3,-1);
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                a[0] = i;
            }
            else if(s[i]=='b'){
                a[1] = i;
            }
            else if(s[i] == 'c'){
                a[2] = i;
            }
           
                cnt+=  *min_element(a.begin(), a.end()) + 1;
            
        }
    return cnt;
    }
};