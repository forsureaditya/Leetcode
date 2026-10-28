class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j-1>=0) matrix[i][j] += matrix[i][j-1];
            }
        }

        for(int col = 0;col<m;col++){
            for(int fcol=col;fcol<m;fcol++){
            int cumsum = 0;
            unordered_map<int,int>mpp;
            mpp[0]++;
            for(int row = 0;row<n;row++){
                cumsum+=matrix[row][fcol];
                if(col-1>=0){
                    cumsum-=matrix[row][col-1];
                }
                int diff = cumsum-target;
                if(mpp.find(diff)!=mpp.end()){
                    cnt+=mpp[diff];
                }
                mpp[cumsum]++;
            }
        }
        }
        return cnt;
    }
};