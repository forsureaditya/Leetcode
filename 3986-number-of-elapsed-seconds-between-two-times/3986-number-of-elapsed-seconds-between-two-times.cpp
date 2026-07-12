class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int num1 = 0;
        int num2 = 0;
        long long n1=0;
        long long n2=0;
        for(int i=0;i<startTime.size();i++){
            if(startTime[i]!=':'){
                num1=num1*10 + (startTime[i]-'0');
            }
            else{
                num1*=60;
                n1=n1*60+num1;
                num1=0;
            }
            if(endTime[i]!=':'){
                num2=num2*10 + (endTime[i]-'0');
            }
            else{
                num2*=60;
                n2=n2*60+num2;
                num2=0;
            }
        }
        n1+=num1;
        n2+=num2;
        return (int)(n2-n1);
    }
};