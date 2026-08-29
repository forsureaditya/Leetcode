class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        // case1:output is 1
        int diffx = abs(source[0]-target[0]);
        int diffy = abs(source[1]-target[1]);
        if(diffx == diffy) return 1;
        // case2:output is 2.
        int blocks = 0;
        if(source[0]%2==0){
            if(source[1]%2==0){
                blocks = 1;
            }
            else{
                blocks = 0;
            }
        }
        else{
            if(source[1]%2==0){
                blocks = 0;
            }
            else blocks = 1;
        }
        int blockt = 0;
        if(target[0]%2==0){
            if(target[1]%2==0){
                blockt = 1;
            }
            else blockt = 0;
        }
        else{
            if(target[1]%2==0){
                blockt = 0;
            }
            else blockt = 1;
        }
        if(blockt == blocks) return 2;
        //case 3:
        return -1;
    }
};