class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>ans;
        for(int i=0;i<asteroids.size();i++){
            if(st.empty() && asteroids[i]>=0){
                st.push(asteroids[i]);
            }
            else{
                if(asteroids[i]<0){
                    while(!st.empty() && st.top()<abs(asteroids[i])){
                        st.pop();
                    }
                    if(st.empty()){
                        ans.push_back(asteroids[i]);
                    }
                    else{
                        if(st.top() == abs(asteroids[i])) st.pop();
                        
                    }
                }
                else st.push(asteroids[i]);
            }
           
        }
         vector<int>ans2;
            while(!st.empty()){
                ans2.push_back(st.top());
                st.pop();
            }
            reverse(ans2.begin(),ans2.end());
            for(auto it: ans2) ans.push_back(it);
            return ans;
    }
};