class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto it: stones){
            pq.push(it);
        }
        while(pq.size()>1){
            int n = pq.top();
            pq.pop();
            n = abs(n-pq.top());
            pq.pop();
            if(n!=0) pq.push(n);
        }
        if(pq.size()==1) return pq.top();
        return 0;
    }   
};