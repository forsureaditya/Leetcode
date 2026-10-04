class Solution {
public:
int func(int a,int b){ 
    int diff = abs(a-b);
    diff = min(abs(a+10-b),diff);
    diff = min(abs(a-(b+10)),diff);
    return diff;
}
    int minRotations(int n, string s) {
      int prefix = 0;
      int suffix = 0;
      int prev = 0;
      for(int i=0;i<s.size();i++){
        int x = s[i]-'0';
        int diff = abs(x-prev);
        diff = min(diff,abs(x+10-prev));
        diff = min(abs(x-(prev+10)),diff);
        prefix+=diff;
        prev = x;
      }  
      prev = 0;
      for(int j=s.size()-1;j>=0;j--){
        int x = s[j]-'0';
        int diff = abs(x-prev);
        diff = min(diff,abs(x+10-prev));
        diff = min(abs(x-(prev+10)),diff);
        suffix+=diff;
        prev = x;
      }
        int ans = 0;
        ans = min(prefix,suffix);
        for(int i=0;i<s.size()-1;i++){
            suffix = prefix + + func(s[i]-'0',s[n-1]-'0')
       - func(s[i]-'0',s[i+1]-'0');
            ans = min(suffix,ans);
        }
      
      return ans;
    }
};