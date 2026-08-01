class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       vector<int>collect;
       collect.push_back(-1);
       for(int i=0;i<nums.size();i++){
        if(nums[i]==0) collect.push_back(i);
       }
       collect.push_back(nums.size());
       int i = 0;
       int j = i+k+1;
       int maxlen;
        if(j>=collect.size()){
            maxlen = (nums.size()-1)-(collect[i]+1)+1;
        }
        else maxlen = (collect[j]-1)-(collect[i]+1)+1;
       while(j<collect.size()){
        maxlen = max(maxlen,(collect[j]-1)-(collect[i]+1)+1);
        i++;
        j++;
       }
       return maxlen;
    }
};