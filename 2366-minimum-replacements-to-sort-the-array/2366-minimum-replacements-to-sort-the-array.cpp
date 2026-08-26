class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long cnt = 0;
        int smlr = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>smlr){
                
                if(nums[i]%smlr==0){
                    int parts = nums[i]/smlr;
                    cnt+=parts-1;

                }
                else{
                    int parts = (int)(nums[i]/smlr) + 1;
                    cnt+=parts-1;
                    smlr = nums[i] / parts;
                }
            }
            else{
                smlr = nums[i];
            }
        }
        return cnt;
    }
};