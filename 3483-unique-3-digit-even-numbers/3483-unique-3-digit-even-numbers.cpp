class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        map<vector<int>,int>mpp;
        int cnt = 0;
        for(int i=0;i<digits.size();i++){
            for(int j=i+1;j<digits.size();j++){
                for(int k=j+1;k<digits.size();k++){
                    vector<int>a = {digits[i],digits[j],digits[k]};
                    sort(a.begin(),a.end());
                    if(mpp.find(a)!=mpp.end()){
                        continue;
                    }
                    mpp[a]++;
                    int even = 0;
                    if(digits[i]%2==0) even++;
                    if(digits[j]%2==0) even++;
                    if(digits[k]%2==0) even++;
                    if(even==0){
                        continue;
                    }
                    else if(even==1){
                        if(digits[i]!=digits[j]&& digits[j]!=digits[k] && digits[k]!=digits[i]){
                            cnt+=2;
                        }
                        else{
                            cnt+=1;
                        }
                    }
                    else if(even==2){
                        if(digits[i]!=digits[j]&& digits[j]!=digits[k] && digits[k]!=digits[i]){
                            cnt+=4;
                            if(digits[i]==0|| digits[j]==0 || digits[k]==0){
                                cnt-=1;
                            }
                        }
                        else{
                            cnt+=2;
                            if(digits[i]==0|| digits[j]==0 || digits[k]==0){
                                cnt-=1;
                            }
                        }
                    }
                    else{
                        if(digits[i]!=digits[j]&& digits[j]!=digits[k] && digits[k]!=digits[i]){
                            cnt+=6;
                            if(digits[i]==0|| digits[j]==0 || digits[k]==0){
                                cnt-=2;
                            }
                        }
                        else if(digits[i]==digits[k] && digits[k] == digits[j]){
                            cnt+=1;
                            if(digits[i]==0) cnt--;
                        }
                        else{
                            cnt+=3;
                            if(digits[i]==0|| digits[j]==0 || digits[k]==0){
                                if(digits[i]==0)cnt-=1;
                                if(digits[j]==0) cnt-=1;
                                if(digits[k]==0) cnt-=1;
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};