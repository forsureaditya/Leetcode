class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        long long ans = 0;
        vector<int>arr;
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            int mini = INT_MAX;
            int maxi = INT_MIN;
            while(x){
                mini=min(mini,x%10);
                maxi=max(maxi,x%10);
                x/=10;
            }
            arr.push_back(maxi-mini);
        }
        int maxii=*max_element(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(arr[i]==maxii){
                ans+=nums[i];
            }
        }
        return ans;
    }
};