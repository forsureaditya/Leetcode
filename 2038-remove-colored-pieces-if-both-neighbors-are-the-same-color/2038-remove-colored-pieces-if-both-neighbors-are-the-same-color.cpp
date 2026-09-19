class Solution {
public:
    bool winnerOfGame(string colors) {
        int cnta = 0;
        int cntb = 0;
        for(int i=1;i<=colors.size()-1;i++){
            if(colors[i]==colors[i-1] && colors[i+1]==colors[i] && colors[i]=='A'){
                cnta++;
            }
            if(colors[i]==colors[i-1] && colors[i+1]==colors[i] && colors[i]=='B'){
                cntb++;
            }
        }
        if(cnta>cntb) return true;
        return false;
    }
};