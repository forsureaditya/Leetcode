class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        vector<long long>ans;
        long long sum = 0;
        for(int i=0;i<tasks.size();i++){
            sum+=tasks[i];
            ans.push_back(sum);
        }
        vector<long long> shifts2;
        for(auto it: shifts) shifts2.push_back(it);
        vector<int>fans(shifts2.size(),0);
        for(int i=0;i<shifts2.size();i++){
            int l = 0;
            int h = ans.size()-1;
            while(l<=h){
                int mid = (h-l)/2 + l;
               
                if(ans[mid]<=shifts2[i]){
            
                    l = mid+1;
                }
                else h = mid-1;
            }
            if(h==-1) {
                fans[i]=ans.size();
                if(i+1<shifts2.size()) shifts2[i+1] += shifts2[i];   
            }
            else if(l==ans.size()) fans[i] = 0;
            else{
                fans[i] = ans.size()-l;
                if(i+1<shifts2.size()) shifts2[i+1] += shifts2[i];

            }
        }
        return fans;
    }
};