class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long cnt = 0;
        int MOD = (int)(1e9+7);
        int diff = k;
        for(int i=0;i<nums.size();i++){
            int count = 0;
            if(diff<nums[i]){
                count = ((nums[i]-diff-1)/k)+1;
                cnt=cnt + count;
                diff=count*k+diff - nums[i];
            }
            else{
                diff = diff - nums[i];
            }
        }
        cnt = cnt%MOD;
        long long ans  = (cnt*cnt + cnt)/2;
        return ans%MOD;
    }
};