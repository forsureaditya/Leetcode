class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<tuple<int,int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                }
            }
        }
        // now it is the time for bfs traversal
        int ans = 0;
        while(!q.empty()){
            int a = get<0>(q.front());
            int b = get<1>(q.front());
            int val = get<2>(q.front());
            q.pop();
            int check = 0;
            if(a-1>=0 && grid[a-1][b] == 1){
                grid[a-1][b] = 2;
                q.push({a-1,b,val+1});
                check = 1;
            }
            if(a+1<n && grid[a+1][b] == 1){
                grid[a+1][b] = 2;
                q.push({a+1,b,val+1});
                check = 1;
            }
            if(b-1>=0 && grid[a][b-1] == 1){
                grid[a][b-1] = 2;
                q.push({a,b-1,val+1});
                check = 1;
            }
            if(b+1<m && grid[a][b+1] == 1){
                grid[a][b+1] = 2;
                q.push({a,b+1,val+1});
                check = 1;
            }
            if(check) ans = val+1;
        }
        // now checking if 1 is remaining or not
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
};