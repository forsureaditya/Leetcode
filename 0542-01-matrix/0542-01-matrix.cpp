class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int dx[]={0,-1,0,+1};
        int dy[]={-1,0,+1,0};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int level = q.front().second;
            
            if(dist[row][col]==0)dist[row][col] = level;
            else dist[row][col] = min(level,dist[row][col]);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol},level+1});
                    vis[nrow][ncol] = 1;
                }
            }
            
        }
        return dist;
    }
};