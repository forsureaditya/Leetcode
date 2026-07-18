class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>fromlft(nums.size());
        vector<int>fromrgt(nums.size());
        int pdt = 1;
        for(int i=1;i<nums.size();i++){
            pdt*=nums[i-1];
            fromlft[i] = (pdt);
        }
        pdt = 1;
        for(int i=nums.size()-2;i>=0;i--){
            pdt*=nums[i+1];
            fromrgt[i] = pdt;
        }
        vector<int> ans;
        ans.push_back(fromrgt[0]);
        for(int i=1;i<nums.size()-1;i++){
            ans.push_back(fromrgt[i]*fromlft[i]);
        }
        ans.push_back(fromlft[nums.size()-1]);
        return ans;
    }
};