class Solution {
public:
    int fun(long long n){
        int cnt = 0;
        while(n){
            cnt++;
            n/=10;
        }
        return cnt;
    }
long long power(long long x, long long y, int MOD){
    long long ans = 1;
    
    while(y){
        if(y % 2 == 1){
            ans = (ans * x) % MOD;
        }
        x = (x * x) % MOD;
        y /= 2;
    }
    
    return ans;
}
    int sumDecoded(vector<long long>& nums) {
        long long sum = 0;
        int MOD = (int)(1e9+7);
        for(int i=0;i<nums.size();i++){
            long long widthi = nums[i]%10;
            long long di = nums[i]/10;
            long long n = di;
            long long pow10 = 1;
            int digit = fun(n);
            string stryi = "";
            while(digit>widthi){
                stryi += to_string(n%10);
                n/=10;
                digit--;
            }
            reverse(stryi.begin(),stryi.end());
            long long yi = stoi(stryi);
            string strxi = "";
            while(digit){
                strxi += to_string(n%10);
                n/=10;
                digit--;
            }
            reverse(strxi.begin(),strxi.end());
            long long xi = stoi(strxi);
            long long sumt = power(xi, yi, MOD);
            sum+=sumt%MOD;
        }
        return sum%MOD;
    }
};