class Solution {
public:
    bool func(vector<vector<int>>& adj,string &colors,vector<int> &vis,int i,int stamp){
        if(adj[i].size()>2) return false;
        queue<pair<int,char>>q;
        q.push({i,colors[i]});
        vis[i] = stamp;
        while(!q.empty()){
            int val = q.front().first;
            char color = q.front().second;
            q.pop();
            
            for(auto it: adj[val]){
                if(vis[it]==stamp) continue;
                vis[it]=stamp;
                if(color == 'R' && colors[it]=='B' ){
                    q.push({it,colors[it]});
                }
                else if(color=='B' && colors[it]=='W'  ){
                    q.push({it,colors[it]});
                }
                else if(color=='W' && colors[it]=='R' ){
                    q.push({it,colors[it]});
                }
                else return false;
            }
        }
        return true;
        
    }
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        vector<vector<int>>adj(colors.size());
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(colors.size(), 0);
        for(int i=0;i<colors.size();i++){
            if(func(adj,colors,vis,i,i+1)) return i;
        }
        return -1;
    }
};