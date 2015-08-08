/*=============================================================================
#     FileName: 44-WildcardMatching.cpp
#         Desc: AC, 16ms
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
        bool isMatch(string s, int index1, string p, int index2) {
            int len1 = s.length(), len2 = p.length(), star = -1, prevS = -1;
            while (index1 < len1) { //don't need to check index2
                char c1 = s[index1], c2 = p[index2];
                if (c1 == c2 || c2 == '?') {
                    index1 ++;
                    index2 ++;
                } else if (c2 == '*') {
                    star = index2;
                    prevS = index1;
                    index2 ++;
                } else {
                    if (star == -1) {
                        return false;
                    }
                    index2 = star + 1;
                    index1 = ++prevS;
                }
            }
            if (len2 == index2) {
                return len1 == index1;
            }
            if (len1 == index1) {
                while (index2 < len2 && p[index2] == '*') {
                    index2 ++;
                }
                return index2 == len2;
            }
            return false;
        }
        bool isMatch(string s, string p) {
            return isMatch(s, 0, p, 0);
        }
        //MLE
        bool isMatchI(string s, string p) {
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
                    if (p[j - 1] == '*' && (dp[i][j - 1] || dp[i - 1][j])) { //don't need a cycle
                        dp[i][j] = true;
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
