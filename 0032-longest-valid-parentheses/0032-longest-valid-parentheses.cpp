class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>forward;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(') forward.push(i);
            else{
                if(!forward.empty()){
                    forward.pop();
                }
            }
        }
        stack<int>backward;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')') backward.push(i);
            else{
                if(!backward.empty()){
                    backward.pop();
                }
            }
        }
        vector<int>vect;
        while(!forward.empty()){
            vect.push_back(forward.top());
            forward.pop();
        }
        while(!backward.empty()){
            vect.push_back(backward.top());
            backward.pop();
        }
        if(vect.size()==0) return s.size();
         sort(vect.begin(),vect.end());
        int ans = 0;
        ans = max(ans,vect[0]);
        for(int i=1;i<vect.size();i++){
            ans = max(ans,vect[i]-vect[i-1]-1);
        }
        ans = max(ans,((int)s.size() - vect[vect.size()-1]-1));
        return ans;
    }
};