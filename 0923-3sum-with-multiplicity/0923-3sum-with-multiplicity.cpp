class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
       long long ans = 0;
       int MOD = 1e9+7;
       for(int i=0;i<arr.size();i++){
        map<int,int>mpp;
        vector<int>temp;
        for(int j=i+1;j<arr.size();j++){
            mpp[arr[j]]++;
        }
        for(auto it: mpp){
            temp.push_back(it.first);
        }
        int j = 0;
        int k = temp.size()-1;
        while(j<k){
            long long sum = arr[i] + temp[j] + temp[k];
            if(sum==target){
                ans+=(mpp[temp[j]]*mpp[temp[k]])%MOD;
                k--;
                j++;
            }
            else if(sum>target){
                k--;
            }
            else j++;
        }
        if(j==k){
            long long sum = arr[i] + temp[j] + temp[k];
            if(sum==target){
                long long pdt= 1LL*(mpp[temp[j]])*(mpp[temp[j]]-1);
                pdt/=2;
                ans+=pdt%MOD;
            }
        }
       } 
       return ans%MOD;
    }
};