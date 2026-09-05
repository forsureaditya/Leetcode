class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<>>left;
        priority_queue<int,vector<int>,greater<>>right;
        priority_queue<int,vector<int>,greater<>>merge;
        int a = candidates;
        int b = costs.size()-candidates-1;
        long long sum = 0;
        if(a<=b){
        for(int i=0;i<=candidates-1;i++){
            left.push(costs[i]);
        }
        for(int i=costs.size()-1;i>=costs.size()-candidates;i--){
            right.push(costs[i]);
        }
        while(a<=b && k){
            if(!left.empty()&&!right.empty()&&left.top()<=right.top() || (right.empty() && !left.empty())){
                sum+=left.top();
                left.pop();
                left.push(costs[a]);
                a++;
            }
            else if(!left.empty()&&!right.empty()&&left.top()>right.top() || (!right.empty() && left.empty())){
                sum+=right.top();
                right.pop();
                right.push(costs[b]);
                b--;
            }
            k--;
        }
        while(k--){
            if(!left.empty()&&!right.empty()&&left.top()<=right.top() || (right.empty() && !left.empty())){
                sum+=left.top();
                left.pop();
            }
            else if(!left.empty()&&!right.empty()&&left.top()>right.top() || (!right.empty() && left.empty())){
                sum+=right.top();
                right.pop();
            }
        }
        }
        else{
            for(int i=0;i<costs.size();i++){
                merge.push(costs[i]);
            }
            while(k--){
                sum+=merge.top();
                merge.pop();
            }
        }
        return sum;
    }   
};