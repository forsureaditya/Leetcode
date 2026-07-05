class Solution {
public:
    string removeDuplicates(string s) {
       stack<char>st;
       string ans;
       for(int i=0;i<s.size();i++){
        while(i<s.size() && st.size()>0 && s[i]==st.top()){
            st.pop();
            i++;
        }
        if(i<s.size())st.push(s[i]);
       } 
       while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
       }
       if(ans.size()==0) return "";
       reverse(ans.begin(),ans.end());
       return ans;

    }
};