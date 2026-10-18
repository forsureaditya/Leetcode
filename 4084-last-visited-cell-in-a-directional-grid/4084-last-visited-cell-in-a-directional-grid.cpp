class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0)); // everything is unvisited now.
        vector<int>lst = {-1,-1};
        int i = 0;
        int j = 0;
        while(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && vis[i][j]==0){
            vis[i][j] = 1;
            lst = {i,j};// last visited is updated.
            if(grid[i][j]=='R'){
            j = j+1;
            }
            else if(grid[i][j]=='L') j = j-1;
            else if(grid[i][j]=='U') i = i-1;
            else i = i + 1;
        }
        return lst;
    }
};