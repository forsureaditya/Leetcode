class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string str = to_string(n);
        int idx = -1;
        for(int i=0;i<str.size()-1;i++){
            if(str[i]-'0'>str[i+1]-'0'){
                idx = i;
                break;
            }
        }
        if(idx==-1) return n;
        int i = idx;
        while(i>=0 && str[idx]==str[i]){
            i--;
        }
        i++;
        string str1 = str.substr(0,i+1);
        str1.back()--;
        string str2 = "";
        for(int j=i+1;j<str.size();j++) str2+='9';

        string final = str1+str2;
        return stoi(final);
    }
};