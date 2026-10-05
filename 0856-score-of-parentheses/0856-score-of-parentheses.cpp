class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        int score = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                // fresh start.
                st.push(score);
                score = 0;
            }
            else{
                if(s[i-1]=='('){
                    score = st.top() + 1;
                }
                else{
                    score = st.top() + score*2;
                }
                st.pop();
            }
        }
        return score;
    }
};