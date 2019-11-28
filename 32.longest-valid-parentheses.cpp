/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s)
    {
        int cnt = 0;
        vector<int> dp(s.size() + 1, 0);

        for (size_t i = 1; i <= s.size(); i++) {
            if (s[i - 1] == '(') {
                cnt++;
            } else {
                if (cnt > 0) {
                    cnt--;
                    dp[i] = 2;
                    if (s[i - 2] == ')')
                        dp[i] += dp[i - 1];
                    dp[i] += dp[i - dp[i]];
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end
