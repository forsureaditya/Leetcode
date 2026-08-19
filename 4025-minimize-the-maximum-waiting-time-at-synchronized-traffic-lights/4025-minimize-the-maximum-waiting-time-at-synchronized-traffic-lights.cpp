class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int mini = INT_MIN;
        sort(lights.begin(),lights.end());
        for(int i=0;i<arrivalTime.size();i++){
            int r = arrivalTime[i]%period;
            int s=0;
            int e=lights.size()-1;
            while(s<=e){
                int mid = s+(e-s)/2;
                if(lights[mid]<=r) s=mid+1;
                else e=mid-1;
            }
            if(s>=lights.size() || lights[s]==r){
                mini = max(mini,period-r);
            }
            else{
                mini = max(mini,0);
            }
        }
        return mini;
    }
};