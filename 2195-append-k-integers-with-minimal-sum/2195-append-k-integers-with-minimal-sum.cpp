class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long prev = 0;
        long long sum = 0;
        for(int i=0;i<nums.size() && k;i++){
            long long diff = nums[i] - prev - 1;
           
            if(diff>0){
                diff = min(diff,k*1LL);
                long long pdt = (prev+1)*diff*1LL;
                long long pdt2 = ((diff)*(diff-1)*1LL)/2;
                sum+=pdt+pdt2;
                k-=diff;
            }
            prev = nums[i];
        }
        if(k){
            long long pdt = (nums[nums.size()-1]+1)*1LL;
            pdt*=k*1LL;
            long long pdt2 = ((long long)(k)*(long long)(k-1)*1LL)/2;
            sum+=pdt;
            sum+=pdt2;
        }
        return sum;
    }
};