class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int cntodd = 0;
        for(auto it: nums1){
            if(it%2!=0) cntodd++;
        }
        int mini = *min_element(nums1.begin(),nums1.end());
        if(mini%2 == 1){
            return true;
        }
        if(mini%2==0 && cntodd == 0) return true;
        return false;
    }
};