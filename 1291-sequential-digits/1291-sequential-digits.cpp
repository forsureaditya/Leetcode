class Solution {
public:
    vector<int> sequentialDigits(int &low, int &high) {
        string str = "123456789";
        int lowdig = 0;
        int highdig = 0;
        int x = low;
        while(x){
            lowdig++;
            x/=10;
        }
        int y = high;
        while(y){
            highdig++;
            y/=10;
        }
        vector<int>ans;
        for(int i=lowdig;i<=highdig;i++){
            int j = 0;
            while(j+i-1<str.size() ){
                if(stoi(str.substr(j,i))<=high && stoi(str.substr(j,i))>=low)ans.push_back(stoi(str.substr(j,i)));
                j++;
            }
        }
        return ans;
    }
};