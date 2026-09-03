class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        for(int i=stones.size()-1;i>=1;i--){
            stones[i-1] = abs(stones[i]-stones[i-1]);
            stones.erase(stones.begin()+i); 
            sort(stones.begin(),stones.end());
        }
        return stones[0];
    }
};