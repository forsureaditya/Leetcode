class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left = 0;
        int right = 0;
        int k = p.size();
        unordered_map<char,int>mpp;
        for(auto it: p){
            mpp[it]++;
        }
        vector<int>ans;
        sort(p.begin(),p.end());
        unordered_map<char,int>mpp2;
        while(right<s.size()){
            mpp2[s[right]]++;
            if(right-left+1>k){
                mpp2[s[left]]--;
                if(mpp2[s[left]]==0){
                    mpp2.erase(s[left]);
                }
                left++;
            }
            if(right-left+1==k){
                if(mpp2==mpp){
                    ans.push_back(left);
                }
                
            }
            right++;
        }
        return ans;
    
    }
};