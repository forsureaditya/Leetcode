class Solution {
public:
    string funcall(string s1,unordered_map<string,int> mpp , string s2){
        next_permutation(s1.begin(),s1.end());
        if(mpp.find(s1)==mpp.end()){
            return s1;
        }
        if(s1==s2){
            return "0";
        }
        return funcall(s1, mpp ,s2);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        unordered_map<string,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(funcall(nums[i],mpp,nums[i])!="0"){
                return funcall(nums[i],mpp,nums[i]);
                
            }
        }
        ans = nums[0];
        for(int i=0;i<ans.size();i++){
            if(ans[i]=='1'){
                ans[i]='0';
                break;
            }
            else{
                ans[i]='1';
                break;
            }
        }
        return ans;
    }
};