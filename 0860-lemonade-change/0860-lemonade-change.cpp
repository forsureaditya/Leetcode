class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5 = 0;
        int cnt10 = 0;
        int cnt20 = 0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                cnt5+=1;
            }
            else{
                if(bills[i]==10 && cnt5>0){
                    cnt5--;
                    cnt10++;
                }
                else if(bills[i]==20 && cnt10==0 && cnt5>=3){
                    cnt20++;
                    cnt5-=3;
                }
                else if(bills[i]==20 && cnt10>0 && cnt5>0){
                    cnt20++;
                    cnt10--;
                    cnt5--;
                }
                else return false;
            }
        }
        return true;
    }
};