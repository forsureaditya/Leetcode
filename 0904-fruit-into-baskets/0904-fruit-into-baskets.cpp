class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        int i = 0;
        int j = 0;
        int k = 0;
        int cnt = 1;
        while(j<fruits.size()){
            if(fruits[j]!=fruits[k] && fruits[j]!= fruits[i]){
                if(cnt){
                    k = j;
                    cnt--;
                }
                else{
                    ans = max(ans,j-i);
                    int z = j-1;
                    while(fruits[z]==fruits[j-1]){
                        z--;
                    }
                    i = z+1;
                    k = j;
                    
                }
            }
            j++;
        }
        ans = max(ans,j-i);
        return ans;
    }
};