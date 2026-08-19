class Solution {
public:
    string breakPalindrome(string palindrome) {
        int i=0;
        int j=palindrome.size()-1;
        unordered_map<char,int>mpp;
        while(i<j){
            if(palindrome[i]=='a' && mpp.find(palindrome[i]) == mpp.end()){
                mpp[palindrome[i]] = max(i,j);
            }
            else if(palindrome[i]!='a' && mpp.find(palindrome[i]) == mpp.end()){
                mpp[palindrome[i]] = min(i,j);
            }
            i++;
            j--;
        }
        int mindx = INT_MAX;
        for(auto it: mpp){
            mindx = min(mindx,it.second);
        }
        if(mindx == INT_MAX) return "";
        if(palindrome[mindx] == 'a') palindrome[mindx] = 'b';
        else palindrome[mindx] = 'a';
        return palindrome;
    }
};