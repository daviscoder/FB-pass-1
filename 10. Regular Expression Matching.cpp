class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.length() == 0) {
            return s.length() == 0? true : false;
        }
        int m = s.length();
        int n = p.length();
        vector<bool> dp (n + 1, false);
        dp[0] = true;
        for (int i = 1; i < dp.size(); i++) {
            if (p[i - 1] == '*') {
                if (i > 1) {
                    dp[i] = dp[i - 2];
                }
            }
        }

        for (int i = 0; i < m; i++) {
            bool prev = dp[0];
            dp[0] = false;
            for (int j = 1; j <= n; j++) {
                bool tmp = dp[j];
                if (p[j - 1] == '.') {
                    dp[j] = prev;
                }
                else if (p[j - 1] == '*') {
                    /*
                      三种情况: 
                        1. *本身忽略，相当于*不起作用: dp[i][j]=dp[i][j - 1]
                        2. *删除前一个字符: dp[i][j - 2]
                        3. *重复之前字符: dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.')
                    */
                    dp[j] = dp[j - 1] || dp[j - 2] || (dp[j] && (s[i] == p[j - 2] || p[j - 2] == '.'));
                }
                else {
                    dp[j] = (p[j - 1] == s[i]) && prev;
                }
                prev = tmp;
            }
        }
        return dp[n];
    }
};
