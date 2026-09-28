class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        //min heap
        priority_queue<tuple<float,int,int>,vector<tuple<float,int,int>>,greater<tuple<float,int,int>>>pq;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                pq.push({(float)arr[i]/(float)arr[j] , arr[i] , arr[j]});
            }
        }
        int x = 1;
        while(x!=k){
            pq.pop();
            x++;
        }
        return {get<1>(pq.top()),get<2>(pq.top())};
    }
};