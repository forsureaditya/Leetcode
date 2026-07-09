class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>left_max;
        vector<int>right_max;
        for(int i=0;i<height.size();i++){
            if(left_max.empty() || left_max.back()<=height[i]){
                left_max.push_back(height[i]);
            } 
            else{
                left_max.push_back(left_max.back());
            }
        }
         for(int i=height.size()-1;i>=0;i--){
            if(right_max.empty() || right_max.back()<=height[i]){
                right_max.push_back(height[i]);
            } 
            else{
                right_max.push_back(right_max.back());
            }
        }
        reverse(right_max.begin(),right_max.end());
        int ans = 0;
        for(int i=0;i<height.size();i++){
            ans+=(min(left_max[i],right_max[i]) - height[i]);
        }
        return ans;
    }
};