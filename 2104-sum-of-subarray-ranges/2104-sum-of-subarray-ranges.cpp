class Solution {
public:
   vector<int> getNGE(vector<int> arr){
      stack<int>st;
      vector<int>ans(arr.size());
      for(int i=arr.size()-1;i>=0;i--){
          while(!st.empty() && arr[st.top()]<=arr[i]){
              st.pop();
          }
          if(st.empty()){
              ans[i]=arr.size();
          }
          else{
              ans[i]=st.top();
          }
          st.push(i);
      }
      return ans;
  }
    vector<int> getPGE(vector<int> arr){
      stack<int>st;
      vector<int>ans(arr.size());
      for(int i=0;i<arr.size();i++){
          while(!st.empty() && arr[st.top()]<arr[i]){
              st.pop();
          }
          if(st.empty()){
              ans[i]=-1;
          }
          else{
              ans[i]=st.top();
          }
          st.push(i);
      }
      return ans;
  }
   long long sumOfMax(vector<int> &arr) {
        // code here
        vector<int>NGE = getNGE(arr);
        vector<int>PGE = getPGE(arr);
        long long ans = 0;
        for(int i=0;i<arr.size();i++){
            int left = i-PGE[i];
            int right = NGE[i]-i;
            ans = ans + ((1LL*left*right)*arr[i]);
        }
        return ans;
    }
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
    long long sumSubarrayMins(vector<int>& arr) {
        vector<int>nsl = nextsmallestleft(arr);
        vector<int>nsr = nextsmallestright(arr);
        long long ans = 0;
        for(int i=0;i<arr.size();i++){
            int left = i-nsl[i];
            int right = nsr[i]-i;
            ans = ans + ((1LL*left*right)*arr[i]);
        }
        return ans;
    }
    long long subArrayRanges(vector<int> &nums) {
      long long ans = sumOfMax(nums) - sumSubarrayMins(nums);
      return ans;
    }
};