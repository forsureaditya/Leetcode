class Solution {
public:
    vector<bool> sieve(int n) {

    vector<bool> primes(n + 1, true);

    primes[0] = primes[1] = false;
    
    for (int i = 2; i * i <= n; i++) {
        if (primes[i]) {
            for (int j = 2; i*j <= n; j ++)
                primes[i*j] = false;
        }
    }
	
  	return primes;
}
    vector<int> maxPrimes(int n, int s) {
       if(s<=1) return {};
        vector<int>ans;
        int sum = 0;
        vector<bool>prime = sieve(n);
       for(int i=2;i<=n;i++){
            if(prime[i]){
                sum+=i;
                if(sum>s) return ans;
                ans.push_back(i);
            }
           
        }
        return ans;
    }
};