class Solution {
public:
    bool judgeSquareSum(int c) {
        // optimal for the solution.....
        long long j=0;
        while(j*j<=c){
            j++;
        }
        long long i=0;
        while(i<=j){
            if(i*i + j*j == c) return true;
            else if(i*i + j*j > c){
                j--;
            }
            else i++;
        }
        return false;
    }
};