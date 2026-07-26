class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        set<vector<int>>ans;
        vector<int>val;
        for(int i=0;i<series1.size();i++){
            val.push_back(series1[i][0]);
        }
        for(int i=0;i<series2.size();i++){
            val.push_back(series2[i][0]);
        }
        sort(val.begin(),val.end());
        int i=0;
        int j = 0;
        int k = 0;
        while(i<val.size()){
            bool flag = false;
            while(j<series1.size() && k<series2.size()){
                if(series1[j][0]<val[i]){
                    j++;
                }
                else if(series2[k][0]<val[i]){
                    k++;
                }
                else{
                    ans.insert({val[i],series1[j][1]+series2[k][1]});
                    
                    flag = true;
                    break;
                }
            }
                if(!flag) break;
               i++; 
        }
        while(i<val.size()){
            bool flag2 = false;
            while(j<series1.size()){
                if(series1[j][0]<val[i]){
                    j++;
                }
                else{
                    ans.insert({val[i],series1[j][1]});
                    j++;
                    flag2 = true;
                    break;
                    
                }
                }
            if(!flag2) break;
               i++; 
        }
        while(i<val.size()){
            while( k<series2.size()){
                
                 if(series2[k][0]<val[i]){
                    k++;
                }
                else{
                    ans.insert({val[i],series2[k][1]});
                    k++;
                    break;
                }
            }
            i++; 
        
        }
            vector<vector<int>>fans;
        for(auto it: ans){
            fans.push_back(it);
        }
            return fans;
    }
};