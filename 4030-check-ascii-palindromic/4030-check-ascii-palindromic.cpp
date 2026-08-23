class Solution {
public:
    bool isPalindromic(string s) {
        string str = "";
        for(auto it: s){
            string binary_string = bitset<8>(it).to_string();
            str+=binary_string;
        }
        int i=0;
        int j=str.size()-1;
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};