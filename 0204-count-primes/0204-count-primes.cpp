class Solution {
public:
    int countPrimes(int n) {
        vector<bool>isprime(n+1,true);
        int ans = 0;
        isprime[0] = false;
        isprime[1] = false;
        for(int i=2;i<n;i++){
            if(isprime[i]){
                ans++;
                for(int j=2;i*j<n;j++){
                    isprime[i*j] = false;
                }
            }
        }
        return ans;
    }
};