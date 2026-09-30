class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()|| vis[i][j]!=0 || grid[i][j]!=1) return ;
        vis[i][j] = 1;
        dfs(i+1,j,grid,vis);
        dfs(i-1,j,grid,vis);
        dfs(i,j-1,grid,vis);
        dfs(i,j+1,grid,vis);
        return ;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),
                        vector<int>(grid[0].size(), 0));
        for(int j=0;j<grid[0].size();j++){
            if(vis[0][j]!=1 && grid[0][j]==1 ){
                    dfs(0,j,grid,vis);
                }
            if(vis[grid.size()-1][j]!=1 && grid[grid.size()-1][j]==1 ){
                    dfs(grid.size()-1,j,grid,vis);
                }
        }
        for(int i=0;i<grid.size();i++){
            if(vis[i][0]!=1 && grid[i][0]==1 ){
                    dfs(i,0,grid,vis);
                }
            if(vis[i][grid[0].size()-1]!=1 && grid[i][grid[0].size()-1]==1 ){
                    dfs(i,grid[0].size()-1,grid,vis);
                }
        }
        int cnt = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};