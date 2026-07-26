class Solution {
public:
    int largestInteger(int n, int s) {
        if(s==0) return 0;
        int cnt = 0;
       
        int ans = 0;
        while(n && s){
            if(s>=9){
                s-=9;
                ans = ans*10+9;
            }
            else{
                ans = ans*10+s;
                s-=s;
            }
            n--;
        }
        while(n){
            ans=ans*10;
            n--;
        }
        if(s) return -1;
        return ans;
    }
};