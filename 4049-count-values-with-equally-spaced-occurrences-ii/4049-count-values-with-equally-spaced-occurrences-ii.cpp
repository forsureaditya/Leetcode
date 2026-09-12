class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int,tuple<int,int,int>>mpp;// first->diff,second->lstidx.
        unordered_map<int,int>del;
        
        for(int i=0;i<nums.size();i++){
            if(del.find(nums[i])!=del.end()){
                continue;
            }
            if(mpp.find(nums[i])==mpp.end()){
                get<0>(mpp[nums[i]]) = 0;
                get<1>(mpp[nums[i]]) = i;
                get<2>(mpp[nums[i]]) = 1;
            }
            else{
                if(get<0>(mpp[nums[i]]) == 0){
                    get<0>(mpp[nums[i]]) = i-get<1>(mpp[nums[i]]);
                    get<1>(mpp[nums[i]]) = i;
                    get<2>(mpp[nums[i]])++;
                }
                else{
                    int diff = i-get<1>(mpp[nums[i]]);
                    if(diff!=get<0>(mpp[nums[i]])){
                        del[nums[i]]++;
                    }
                    else{
                        get<1>(mpp[nums[i]]) = i;
                        get<2>(mpp[nums[i]])++;
                    }
                }
            }
        }
        int cnt = 0;
        for(auto it: mpp){
            if(del.find(it.first)==del.end() && get<2>(it.second) >= 3)
        cnt++;
        }
        return cnt;
    }
};