class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
    vector<vector<int>>ans(nums.size());
      for(int i=0;i<nums.size();i++){
          int n = nums[i];
          for(int j=2; (long long)j*j<=n; j++){
    if(n%j==0){
        ans[i].push_back(j);
        while(n%j==0) n/=j;
    }
}
if(n!=1) ans[i].push_back(n);
      }
     int l = 0;
     int r = 0;
        int mans = 0;
        unordered_map<int,int>mpp;
        while(r<nums.size()){
            for(int i=0;i<ans[r].size();i++){
                mpp[ans[r][i]]++;
            }
            if(mpp.size()>k){
                while(mpp.size()>k){
                    for(int i=0;i<ans[l].size();i++){
                        mpp[ans[l][i]]--;
                        if(mpp[ans[l][i]]==0){
                            mpp.erase(ans[l][i]);
                        }
                    }
                    l++;
                }
            }
            mans = max(mans,r-l+1);
            r++;
        }
        return mans;
    }
};