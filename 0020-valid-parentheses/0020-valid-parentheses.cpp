class Solution {
public:
    bool isValid(string str) {
       stack<char>st;
       st.push(str[0]);
       for(int i = 1;i<str.size();i++){
        if(st.size()==0){
            if(str[i]=='}' || str[i]==')' || str[i]==']') return false;
            else st.push(str[i]);
        }
        else if(st.top()=='('){
            if(str[i]=='}' ||  str[i]==']') return false;
            if(str[i]==')') st.pop();
            else {
            if(str[i]=='(' || str[i] == '{' || str[i]=='[')st.push(str[i]);
            }
        }
        else if(st.top()=='['){
            if(str[i]=='}' || str[i]==')') return false;
            if(str[i]==']') st.pop();
            else {
            if(str[i]=='(' || str[i] == '{' || str[i]=='[')st.push(str[i]);
            }
        }
        else if(st.top()=='{'){
            if(str[i]==')' || str[i]==']') return false;
            if(str[i]=='}') st.pop();
            else{ 
            if(str[i]=='(' || str[i] == '{' || str[i]=='[')st.push(str[i]);
            }
        }
       }
       if(st.size()==0) return true;
       return false;
    }
};
// it is very simple question. with a easy implementation of stack DS.