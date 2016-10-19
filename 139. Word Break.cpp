// O (n^2), O (n)

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 0; j < i; j++) {
                string current = s.substr(j, i - j);
                if (dp[j] && wordDict.count(current)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};
