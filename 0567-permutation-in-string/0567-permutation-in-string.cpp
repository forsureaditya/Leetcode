class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0;
        int right = 0;
        int k = s1.size();
        string str = "";
        sort(s1.begin(),s1.end());
        while(right<s2.size()){
            str+=s2[right];
            if(right-left+1>k){
                left++;
            }
            if(right-left+1==k){
                string x = str.substr(left);
                sort(x.begin(),x.end());
                if(x==s1) return true;
            }
            right++;
        }
        return false;
    }
};