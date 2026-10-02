class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int ans = 0; // maximal answer.
        for(int i=0;i<nums.size();i++){
            int sum = 0;
            unordered_map<int,int>mpp;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                int a = ((2*nums[j])%k+k)%k;
                mpp[a]++;
                if(sum%k==0){
                    ans = max(j-i+1,ans);
                }
                else{
                    int b = (sum%k+k)%k;
                    if(mpp.find(b)!=mpp.end()){
                        ans = max(j-i+1,ans);
                    }
                }
            }
        }
        return ans;
    }
};