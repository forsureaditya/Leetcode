class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        map<int,int>mpp;
        for(auto it: hand){
            mpp[it]++;
        }
        int n = hand.size();
        if(n%groupSize!=0) return false;
        while(n){
            int lst = -1;
            int grp = groupSize;
            vector<int>arrdel;
            int check = 0;
            for(auto it: mpp){
                if((lst==-1||lst+1==it.first) && grp){
                    mpp[it.first]--;
                    if(mpp[it.first]==0) arrdel.push_back(it.first);
                    grp--;
                    lst = it.first;
                }
                else if(lst+1!=it.first) return false;
                if(grp==0) {
                    check = 1;
                    break;
                }
            }
            for(auto it:arrdel){
                cout<<it<<" ";
                mpp.erase(it);
            }
            if(check)n-=groupSize;
            else return false;
        }
        return true;
    }
};