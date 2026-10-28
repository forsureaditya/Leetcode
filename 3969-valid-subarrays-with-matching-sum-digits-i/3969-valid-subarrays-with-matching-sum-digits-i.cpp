class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        // solving this by enumerating pairs.
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            long long sum = 0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                long long val1 = sum;
                while(val1/10){
                    val1/=10;
                }
                int val2 = sum%10;
                if(val1==x && val2==x){
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};