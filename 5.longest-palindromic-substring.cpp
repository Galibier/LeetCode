/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
class Solution {
   public:
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;

        string max = s.substr(0, 1);
        for (int i = 0; i < s.size() - 1; i++) {
            string first = helper(s, i, i);
            if (first.size() > max.size())
                max = first;

            string second = helper(s, i, i + 1);
            if (second.size() > max.size())
                max = second;
        }
        return max;
    }

   private:
    string helper(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[right] == s[left]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - 1 - left);
    }
};
