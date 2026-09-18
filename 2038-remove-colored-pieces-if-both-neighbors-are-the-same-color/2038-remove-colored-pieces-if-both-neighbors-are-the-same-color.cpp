class Solution {
public:
    bool winnerOfGame(string colors) {
        int cnta = 0;
        string stra = "AAA";
        int cntb = 0;
        string strb = "BBB";
        for(int i=0;i<=(int)colors.size()-3;i++){
            if(colors.substr(i,3)==stra){
                cnta++;
            }
            if(colors.substr(i,3)==strb){
                cntb++;
            }
        }
        if(cnta>cntb) return true;
        return false;
    }
};