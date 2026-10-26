class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int till = -1;
        for(int i=0;i<arr.size();i++){
            if(till<i){
                ans++;
                till = arr[i];
            }
            else{
                till = max(arr[i],till);
            }
        }
        return ans;
    }
};