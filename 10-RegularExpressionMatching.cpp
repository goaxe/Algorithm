/*=============================================================================
#     FileName: 10-RegularExpressionMatching.cpp
#         Desc: AC, 84ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-02 13:05:32
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        bool isMatch(string s, string p) {
            return isMatch(s, 0, p, 0);
        }

        bool isMatch(string &s, int pos1, string &p, int pos2) {
            int len1 = s.length(), len2 = p.length();
            if (pos2 == len2) {
                return pos1 == len1;
            }
            if (pos1 == len1) {
                if ((len2 - pos2) % 2) {
                    return false;
                }
                for (int i = pos2 + 1; i < len2; i += 2) {
                    if (p[i] != '*') {
                        return false;
                    }
                }
                return true;
            }
            char c1 = s[pos1], c2 = p[pos2];
            if (len2 > pos2 + 1 && p[pos2 + 1] == '*') {
                if (c2 == '.') {
                    for (int i = pos1; i <= len1; i ++) {
                        if (isMatch(s, i, p, pos2 + 2)) {
                            return true;
                        }
                    }
                    return false;
                } else {
                    if (isMatch(s, pos1, p, pos2 + 2)) {
                        return true;
                    }
                    for (int i = pos1 + 1; i <= len1; i ++) {
                        if (s[i - 1] != c2) {
                            break;
                        }
                        if (isMatch(s, i, p, pos2 + 2)) {
                            return true;
                        }
                    }
                    return false;
                }
            } else if (c1 == c2 || c2 == '.') {
                return isMatch(s, pos1 + 1, p, pos2 + 1);
            } else {
                return false;
            }
        }
};

int main() {
    Solution solution;
    cout << solution.isMatch("aa", "a") << endl;
    cout << solution.isMatch("aa", "aa") << endl;
    cout << solution.isMatch("aaa", "a") << endl;
    cout << solution.isMatch("aa", "a*") << endl;
    cout << solution.isMatch("aa", ".*") << endl;
    cout << solution.isMatch("aa", ".*") << endl;
    cout << solution.isMatch("ab", ".*") << endl;
    cout << solution.isMatch("aab", "c*a*b") << endl;
    cout << solution.isMatch("aaa", "a.a") << endl;
    cout << solution.isMatch("a", "ab*") << endl;

    return 0;

}
