class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
      sort(costs.begin(),costs.end());
      vector<long long>sum;
      long long prevsum = 0;
      for(int i=0;i<costs.size();i++){
        sum.push_back(prevsum+costs[i]);
        prevsum+=costs[i];
      }
      int ans = -1;
      for(int i=0;i<sum.size();i++){
        if(sum[i]<=coins){
            ans = i;
        }
      }  
      if(ans == -1) return 0;
      return ans+1;
    }
};