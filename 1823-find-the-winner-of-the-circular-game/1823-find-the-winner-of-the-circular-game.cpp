class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>arr;
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
        int i = 0;
        int cnt = 1;
        while(arr.size()!=1){
         if(cnt<k){
             cnt++;
             i = (i+1)%arr.size();
         }   
         else{
             arr.erase(arr.begin()+i);
             cnt = 1;
         }
        }
        return arr[0];
    }
};