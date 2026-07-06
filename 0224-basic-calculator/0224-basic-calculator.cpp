class Solution {
public:
    int calculate(string s) {
        long long number = 0;
        long long result = 0;
        int sign = 1;
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ') continue;
            else if(s[i]=='+'){
                result+=number*sign;
                sign = 1;
                number = 0;
            }
            else if(s[i]=='-'){
                result+=number*sign;
                sign = -1;
                number = 0;
            }
            else if(s[i]=='('){
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            }
            else if(s[i]==')'){
                result+=number*sign;
                result = result*st.top();
                st.pop();
                result+=st.top();
                st.pop();
                number = 0;
            }
            else{
                number = number*10 + (s[i]-'0');

            }
        }
        result+= number*sign;
        return result;
    }
};