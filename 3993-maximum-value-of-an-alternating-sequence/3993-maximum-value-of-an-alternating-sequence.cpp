class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n==1) return s;
        long long maxi = (long long)s + (long long)(n/2)*(long long)(m-1);
        maxi++;
        return maxi;
    }
};