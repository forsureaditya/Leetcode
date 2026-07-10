class Solution {
public:
    vector<int> getNSR(vector<int>arr){
        stack<int>st;
        vector<int>ans(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=arr.size();
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> getNSL(vector<int>arr){
        stack<int>st;
        vector<int>ans(arr.size());
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i]=-1;
            else ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> getNLR(vector<int> arr){
        stack<int>st;
        vector<int>ans(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=arr[i];
            }
            else{
                ans[i]=st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
    vector<int> getNLL(vector<int> arr){
        stack<int>st;
        vector<int>ans(arr.size());
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && st.top()<arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=arr[i];
            }
            else{
                ans[i]=st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& h) {
        vector<int>NSR = getNSR(h);
        vector<int>NSL = getNSL(h);
        vector<int>NLR = getNLR(h);
        vector<int>NLL = getNLL(h);
        int ans = 0;
        for(int i=0;i<h.size();i++){
            int width = NSR[i]-NSL[i]-1;
            int height = h[i];
            ans = max(ans,width*height);
        }
        return ans;
    }
};