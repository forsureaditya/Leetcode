class Solution {
public:
    vector<int>  nextsmallestleft(vector<int>arr){
        stack<pair<int,int>>st;
        vector<int>ans(arr.size());
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && st.top().first>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top().second;
            }
            st.push({arr[i],i});
        }
        return ans;
    }
    vector<int>  nextsmallestright(vector<int>arr){
        stack<pair<int,int>>st;
        vector<int>ans(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && st.top().first>arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=arr.size();
            }
            else{
                ans[i]=st.top().second;
            }
            st.push({arr[i],i});
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = (int)1e9+7;
        vector<int>nsl = nextsmallestleft(arr);
        vector<int>nsr = nextsmallestright(arr);
        long long ans = 0;
        for(int i=0;i<arr.size();i++){
            int left = i-nsl[i];
            int right = nsr[i]-i;
            ans = (ans + ((long long)(right*left)*arr[i])%MOD) % MOD;
        }
        return ans;
    }
};