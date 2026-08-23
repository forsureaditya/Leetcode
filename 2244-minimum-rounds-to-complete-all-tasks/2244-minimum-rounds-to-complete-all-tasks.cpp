class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mpp;
        for(int i=0;i<tasks.size();i++){
            mpp[tasks[i]]++;
        }
        int rounds = 0;
        for(auto it: mpp){
            if(it.second%2==0){    
            int i=0;
            while(3*i<it.second){
                i+=2;
            }
            if(i==0){
                rounds+= (it.second)/2;
            }
            else if(3*i==it.second){
                rounds+=i;
            }
            else{
                rounds+= (i-2 + (it.second-3*(i-2))/2);
            }
            }
            else{
                int i=1;
                while(3*i<it.second){
                    i+=2;
                }
                if(it.second == 1) return -1;
                else if(3*i == it.second){     
                 rounds += i;
                 }
                else{
                    rounds+=(i-2+(it.second-3*(i-2))/2);
                }
            }
        }
        return rounds;
    }
};