class Solution {
public:
    long long binarytodecimal(string str){
        int i = str.size()-1;
        int cnt = 0;
        long long ans = 0;
        while(i>=0){
            if(str[i]=='1'){
                ans += pow(2,cnt);
                cnt++;
            }
            else{
                cnt++;
            }
            i--;
        }
        return ans;
    }
    int tobinary(int n ){
        vector<int> val;
        int r = 2;
        while(n){
            val.push_back(n%r);
            n/=r;
        }
        reverse(val.begin(),val.end());
        int ans = 0;
        for(auto it: val){
            ans = ans*10 + it;
        }
        return ans;
    }
    int maxGoodNumber(vector<int>& nums) {
        string s = "";
        long long ans = 0;
         for(int i=0;i<nums.size();i++){
            s+=to_string(tobinary(nums[i]));
         }
        ans = max(ans,binarytodecimal(s));
        next_permutation(nums.begin(),nums.end());
         s = "";
        for(int i=0;i<nums.size();i++){
            s+=to_string(tobinary(nums[i]));
         }
        ans = max(ans,binarytodecimal(s));
        next_permutation(nums.begin(),nums.end());
        s = "";
        for(int i=0;i<nums.size();i++){
            s+=to_string(tobinary(nums[i]));
         }
        ans = max(ans,binarytodecimal(s));
        next_permutation(nums.begin(),nums.end());
         s = "";
        for(int i=0;i<nums.size();i++){
            s+=to_string(tobinary(nums[i]));
         }
        ans = max(ans,binarytodecimal(s));
        next_permutation(nums.begin(),nums.end());
        s = "";
        for(int i=0;i<nums.size();i++){
            s+=to_string(tobinary(nums[i]));
         }
        ans = max(ans,binarytodecimal(s));
        next_permutation(nums.begin(),nums.end());
       s = "";
        for(int i=0;i<nums.size();i++){
            s+=to_string(tobinary(nums[i]));
         }
        ans = max(ans,binarytodecimal(s));
        return ans;
    }
};