class Solution {
public:
    int jump(vector<int>& nums) {
        int maxi = 0;
        int cnt = 0;
        for(int i=0;i<nums.size()-1;i++){
           int fdx = -1;
           int sum = nums[i] + i;
           int j = i+1;
           int maxsum = 0;
           while(j<nums.size() && j<=sum){
            if(maxsum <= nums[j] + j){
                maxsum = nums[j]+j;
                fdx = j;
            }
            j++;
           }
           if(sum >= nums.size()-1){
            cnt++;
            return cnt;
           }
          if(fdx!=-1) {
            i = fdx-1;
            cnt++;
          }
        else{
            if(sum<nums.size())i = sum;
            else i = nums.size()-1;
            cnt++;
        }
        }
        return cnt;
    }
};