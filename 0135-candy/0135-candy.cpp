class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>ans1(n,1);
        
        for(int i=n-2;i>=0;i--){
    if(ratings[i]>ratings[i+1] && ans1[i]<=ans1[i+1]){
        ans1[i]+=ans1[i+1];
    }
}
        vector<int>ans2(n,1);

       for(int i=1;i<n;i++){
       if(ratings[i]>ratings[i-1] && ans2[i]<=ans2[i-1]){
         ans2[i]+=ans2[i-1];
     }
 }
        int fans = 0;
        for(int i=0;i<n;i++){
            fans+= max(ans1[i],ans2[i]);
        }
        return fans;
    }
};