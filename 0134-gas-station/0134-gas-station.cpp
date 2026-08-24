class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0;i<gas.size();i++) sum1+=gas[i];
        for(int i=0;i<cost.size();i++) sum2+=cost[i];
        if(sum1<sum2) return -1;
        int total = 0;
        int result = 0;
        for(int i=0;i<gas.size();i++){
            total+=gas[i]-cost[i];
            if(total<0){
                result = i+1;
                total = 0;
            }
        }
        return result;
    }
};