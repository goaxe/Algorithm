/*=============================================================================
#     FileName: 44-WildcardMatching.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-07 23:57:17
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        //MLE
        bool isMatch(string s, string p) {
            if (p == "") {
                return s == "";
            }
            if (s == "") {
                while (p != "" && p[0] == '*') {
                    p = p.substr(1, p.length() - 1);
                }
                return p == "";
            }
            int len1 = s.length(), len2 = p.length();
            vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, false));
            dp[0][0] = true;
            for (int i = 1; i <= len1; i ++) {
                dp[i][0] = false;
            }
            for (int j = 1; j <= len2; j ++) {
                dp[0][j] = dp[0][j - 1] && (p[j - 1] == '*');
            }
            for (int i = 1; i <= len1; i ++) {
                for (int j = 1; j <= len2; j ++) {
                    if (dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?')) {
                        dp[i][j] = true;
                        continue;
                    }
                    if (p[j - 1] == '*') {
                        for (int k = 0; k <= i; k ++) {
                            if (dp[k][j - 1]) {
                                dp[i][j] = true;
                                break;
                            }
                        }
                    }
                }
            }

            return dp[len1][len2];
        }
};

int main() {
    Solution solution;
    cout << solution.isMatch("aa", "a") << endl;
    cout << solution.isMatch("aa", "aa") << endl;
    cout << solution.isMatch("aaa", "aa") << endl;
    cout << solution.isMatch("aa", "*") << endl;
    cout << solution.isMatch("aa", "a*") << endl;
    cout << solution.isMatch("ab", "?*") << endl;
    cout << solution.isMatch("aab", "c*a*b*") << endl;
    return 0;
}
