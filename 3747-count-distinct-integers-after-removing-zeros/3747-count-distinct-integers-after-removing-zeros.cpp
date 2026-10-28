class Solution {
public:
    long long countDistinct(long long n) {
        long long x = n;
        int cntdig = 0;
        while(x){
            cntdig++;
            x/=10;
        }
        long long ans = 0;
        long long pdt = 9;
        for(int i=1;i<cntdig;i++){
            ans+=pdt;
            pdt*=9;
        }

        // we have to find out how may cntdig numbers are there.
        string str = to_string(n);
        int check = 1;
        for(int i=0;i<str.size()-1;i++){
            if(str[i]=='0') {
                check = 0;
                break;
            }
            long long val = str[i]-'0'-1;
            long long p = 1;
            int loop = str.size()-i-1;
            while(loop--){
                p*=9;
            }
            val = val*p;
            ans+=val;
        }
        if(check)ans+=str[str.size()-1]-'0';
        return ans;
    }
};