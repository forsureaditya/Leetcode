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
           long long sumt = (long long)pow(xi, yi); 
            sum+=sumt%MOD;
        }
        return sum%MOD;
    }
};