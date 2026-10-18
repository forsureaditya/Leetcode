class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int lst = nums[0];
        int cnt = 0;
        for(int i=1;i<nums.size();i++){
            if(lst==nums[i]){
                cnt++;
            }
            else{
                lst = nums[i];
            }
        }
        return cnt;
    }
};