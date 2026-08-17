class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
       sort(tokens.begin(),tokens.end());
       int i=0;
       int j=tokens.size()-1;
       int count=0;
       int maxcount = 0;
       while(i<=j ){
        if(tokens[i]<=power){
            power = power - tokens[i];
            count++;
            i++;
            maxcount = max(maxcount,count);
        }
        else if(tokens[i]>power && count>=1){
            power = power+tokens[j];
            maxcount = max(maxcount,count);
            count--;
            j--;
        }
        else if(tokens[i]>power && count==0) break;
       } 
       maxcount = max(maxcount,count);
       return maxcount;
    }
};