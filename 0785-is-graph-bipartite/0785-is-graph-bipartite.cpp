class Solution {
    bool bfs(int n,vector<vector<int>>&graph,vector<int>&visited){
        visited[n] = 0;
        queue<pair<int,int>>q;
        q.push({n,0});
        while(!q.empty()){
            int val = q.front().first;
            int level = q.front().second;
            q.pop();
            for(auto it: graph[val]){
                if(!visited[it]){
                    visited[it] = level+1;
                    q.push({it,level+1});
                }
                else{
                    if(visited[it]==level){
                        return false;
                    }
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>visited(graph.size(),0);
        for(int i=0;i<graph.size();i++){
           if(!visited[i]) if(bfs(i,graph,visited)==false) return false;
        }
        return true;
    }
};