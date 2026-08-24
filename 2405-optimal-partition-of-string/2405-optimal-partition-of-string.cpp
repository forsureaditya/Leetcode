class Solution {
public:
    int partitionString(string s) {
        int count = 0;
        for(int i=0;i<s.size();i++){
            unordered_map<int,int>mpp;
            while(i<s.size() && mpp.find(s[i])==mpp.end()){
                mpp[s[i]]++;
                i++;
            }
            count++;
            i--;
        }
        return count;
    }
};