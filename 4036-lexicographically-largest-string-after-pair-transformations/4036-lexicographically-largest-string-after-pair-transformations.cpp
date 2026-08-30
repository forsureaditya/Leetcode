class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string>ans;
        for(int i=0;i<nums.size();i++){
            long long n =nums[i];
            string str = "";
           while(n!=0){
             long long i = 1;
             long long cnt = 0;
             while(n/i!=0 && cnt<26){
                 i*=2;
                 cnt++;
             }
             i /= 2;   
             cnt--;    
             n = n - i; 
             if(cnt>=25) str.push_back('z');
             else str.push_back('a'+cnt);
             
            }
            ans.push_back(str);
        }
        return ans;
    }
};