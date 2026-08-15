class Solution {
public:
    int func(string s, string temp, int a) {
        if (s == temp)
            return INT_MAX;
        int ans = a;
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                if (s[i] - 'a' > s[j] - 'a') {
                    ans += min(((s[i] - 'a') - (s[j] - 'a')),
                               ((26 + s[j] - 'a') - (s[i] - 'a')));
                } else {
                    ans += min(((s[j] - 'a') - (s[i] - 'a')),
                               ((26 + s[i] - 'a') - (s[j] - 'a')));
                }
            }
            i++;
            j--;
        }
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.end() - 1);
        ans = min(ans, func(s, temp, a + 1));
        return ans;
    }
    int minOperations(string s) {
        int ans = 0;
        int i = 0;
        int j = s.size() - 1;
        string temp = s;
        while (i < j) {
            if (s[i] != s[j]) {
                if (s[i] - 'a' > s[j] - 'a') {
                    ans += min(((s[i] - 'a') - (s[j] - 'a')),
                               ((26 + s[j] - 'a') - (s[i] - 'a')));
                } else {
                    ans += min(((s[j] - 'a') - (s[i] - 'a')),
                               ((26 + s[i] - 'a') - (s[j] - 'a')));
                }
            }
            i++;
            j--;
        }
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.end() - 1);
        ans = min(ans, func(s, temp, 1));
        return ans;
    }
};