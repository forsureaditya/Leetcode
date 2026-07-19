class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int i = 0;
        int j = 1;
        int diff = abs(target[i]+target[j]-start[i]-start[j]);
        if(diff%2==0) return true;
        else return false;
    }
};