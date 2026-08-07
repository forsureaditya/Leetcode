class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int>idx;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0) idx.push_back(i);
        }
        int cnt = 0;
        for(int i = 0; i + k <= idx.size();i++){
        int left = (i-1 < 0) ? (idx[i] + 1) : (idx[i] - idx[i-1]);
        int right = (i+k < idx.size()) ? (idx[i+k] - idx[i+k-1]):(nums.size() - idx[i+k-1]);
        cnt += left * right;
        }
        return cnt;
    }
};