/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dp(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dp[s[i]] > start)
                start = dp[s[i]];
            dp[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};
