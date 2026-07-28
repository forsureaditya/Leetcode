class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int>mpp;
        for(auto it: s){
            mpp[it]++;
        }
        int st = 0;
        int e = s.size()-1;
        int mid = (st+e)/2;
        string ans(s.size(),'a');
        for(auto it:mpp){
            if(it.second%2==0){
                int n = it.second;
                while(n){
                    ans[st] = it.first;
                    st++;
                    n--;
                    ans[e] = it.first;
                    e--;
                    n--;
                }
            }
            else{
                int n = it.second;
                while(n>1){
                   
                   
                    ans[e] = it.first;
                    e--;
                    n--;
                    if(n==1) break;
                    ans[st] = it.first;
                    st++;
                    n--;
                }
                if(n==1){
                    ans[mid] = it.first;
                    mid++;
                    n--;
                }
            }
        }
        return ans;
    }
};