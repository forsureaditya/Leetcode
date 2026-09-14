class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
    if(nums.size()==1) return {nums[0]};
    vector<int>ans;
        ans.push_back(nums[0]);
        int maxi=0;
        int a=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>a){
                ans.push_back(nums[i]);
                a=nums[i];
                maxi=i;
            }
        } int m=ans.size();
        if(maxi==nums.size()-1) return ans;
        else {int b=nums[nums.size()-1];
        ans.push_back(b);
        for(int i=nums.size()-2;i>maxi;i--){
            if(nums[i]>b){
                ans.push_back(nums[i]);
                b=nums[i];
            }
        }
        reverse(ans.begin()+m,ans.end());
        }
        return ans;

    }
};