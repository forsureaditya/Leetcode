class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int>indegree(numCourses,0);
        for(int i=0;i<adj.size();i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int>collect;
        while(!q.empty()){
            int val = q.front();
            collect.push_back(val);
            q.pop();
            for(auto it: adj[val]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(collect.size()==numCourses) return collect;
        return {};
    }
};