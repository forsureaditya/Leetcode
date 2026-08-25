class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int>collect(101,0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]%k==0){
                collect[nums[i]/k] = 1;
            }
        }
        int ans = 101;
        for(int i=1;i<101;i++){
            if(collect[i]==0){
                ans = i;
                break;
            }
            
        }
        return ans*k;
    }
};