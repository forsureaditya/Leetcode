class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 2) return nums.size();
        int i = 2;
        while(i<=nums.size()){
            i*=2;
        }
        return i;
    }
};