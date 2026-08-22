class Solution {
public:
    bool checkDivisibility(int n) {
        int x = n;
        int pdt = 1;
        int sum = 0;
        while(x){
            pdt = pdt*(x%10);
            sum = sum+(x%10);
            x/=10;
        }
        if(n%(pdt+sum)==0) return true;
        return false;
    }
};