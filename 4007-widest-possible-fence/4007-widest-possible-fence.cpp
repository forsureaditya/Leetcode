class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int,int>mpp;
        unordered_map<int,int>npp;
        for(auto it: planks) {
            mpp[it]++;
            npp[it]++;
        }
        vector<int>arr;
        for(auto it:npp){
            arr.push_back(it.first);
        }
        unordered_map<int,int>f;
        int maxcnt = 0;
        for(int i=0;i<arr.size();i++){
            for(int j=i;j<arr.size();j++){
                if(i!=j) f[arr[i]+arr[j]] += min(npp[arr[i]],npp[arr[j]]);
                else{
                    if(npp[arr[j]]==1) continue;
                    else f[arr[i]+arr[j]] += npp[arr[i]]/2;
                }
            }
        }
        for(auto it: mpp){
            f[it.first] += it.second; 
        }
        for(auto it : f){
            maxcnt = max(maxcnt,it.second);
        }
        return maxcnt;
    }
};