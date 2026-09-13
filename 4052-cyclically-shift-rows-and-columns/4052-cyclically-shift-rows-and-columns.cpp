class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>>ans(n,vector<int>(n));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
               ans[i][(j-rowShift[i]+n)%n] = grid[i][j]; 
            }
        }
        // try to cout.
        vector<vector<int>>fans(n,vector<int>(n));
        for(int i=0;i<grid.size();i++){//act like row
            for(int j=0;j<grid.size();j++){//act like col
                fans[(j-colShift[i]+n)%n][i] = ans[j][i];
            }
            
        }
        return fans;
    }
};