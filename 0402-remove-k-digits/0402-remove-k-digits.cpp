class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && k && (st.top()-'0')>(num[i]-'0')){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k){
            st.pop();
            k--;
        }
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        if(ans.empty()) return "0";
        reverse(ans.begin(),ans.end());
        int i=0;
        while((ans[i]-'0')==0){
            i++;
        }
        string ans2 =  ans.substr(i,ans.size()-i);
        if(ans2.empty()) return "0";
        return ans2;
    }
};