class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
    
    for(int i=0;i<tasks.size();i++){
        tasks[i].push_back(i);
    }
    sort(tasks.begin(),tasks.end());
    int totaltime = 0;
    vector<int>ans;
    priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> pq;

    for(int i=0;i<tasks.size();i++){
        int currtime = tasks[i][0];
        if(currtime < totaltime){
            pq.push({tasks[i][1],tasks[i][2]});
        }
        else if(currtime == totaltime){
            pq.push({tasks[i][1],tasks[i][2]});
            pair<int,int>x = pq.top();
            pq.pop();
            totaltime += x.first;
            ans.push_back(x.second);
        }
        else{
           if(pq.size()){

            pair<int,int>x = pq.top();
            pq.pop();
            totaltime += x.first;
            ans.push_back(x.second);
           }
           else {
            totaltime = currtime;
           }
            i--;
            
            
        }
    }
    while(pq.size()){
            pair<int,int>x = pq.top();
            pq.pop();
            ans.push_back(x.second);
    }
    return ans;
    }
};