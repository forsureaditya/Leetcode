class Solution {
public:
    int calculateScore(int a, int b) {
        int cnt = 0;
        int s1 = 0;
        int s2 = 0;
        while(cnt<=31){
            if(a&(1<<cnt)) s1++;
            if(b&(1<<cnt)) s2++;
            cnt++;
        }
        if(s1>=s2) return s1*s2;
        return s2/s1;
    }
};