class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){\
            int cnt = 0;
            while(nums[i]){
                cnt+=nums[i]%10;
                nums[i]/=10;
            }
            if(cnt==i) return i;
        }
        return -1;
    }
};