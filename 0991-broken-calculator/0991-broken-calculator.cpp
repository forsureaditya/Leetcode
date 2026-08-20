class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int n = startValue;
        int m = target;
        int cnt = 0;
        while(n<m){
            if(m%2==0)m/=2;
            else m++;
            cnt++;
        }
        cnt+=n-m;
        return cnt;
    }
};