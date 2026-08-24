class Solution {
public:
    string predictPartyVictory(string senate) {
        int rcnt = 0;
        int dcnt = 0;
        for(int i = 0;i<senate.size();i++){
           if(senate[i]=='D'){
            dcnt++;
           } 
           else{
            rcnt++;
           }
        }
        int i=0;
        while(rcnt!=0 && dcnt!=0){
            if(i==senate.size()){
                i=0;
            }
            if(senate[i]=='D'){
                rcnt--;
                int j = (i+1)%senate.size();
                while(j!=i && senate[j]!='R') j = (j+1)%senate.size();
                senate.erase(j,1);
                if(j<i){
                    i--;
                }
                
            }
            else{
                dcnt--;
                int j = (i+1)%senate.size();
                while(j!=i && senate[j]!='D') j = (j+1)%senate.size();
                senate.erase(j,1);
                if(j<i){
                    i--;
                }
               
            }
           i++;
        }
        if(rcnt == 0) return "Dire";
        return "Radiant";
    }
};