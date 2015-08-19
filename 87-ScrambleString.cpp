/*=============================================================================
#     FileName: 87-ScrambleString.cpp
#         Desc: AC, 16ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-13 17:28:37
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        if (len1 != len2) {
            return false;
        }
        if (len1 == 1) {//this is very important
            return s1 == s2;
        }
        if (!len1) {
            return true;
        }
        string st1 = s1, st2 = s2;
        sort(st1.begin(), st1.end());
        sort(st2.begin(), st2.end());
        if (st1 != st2) {
            return false;
        }
        for (int i = 1; i < len1; i ++) {
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) || (isScramble(s1.substr(0, i), s2.substr(len1 - i)) && isScramble(s1.substr(i), s2.substr(0, len1 - i)))) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    cout << solution.isScramble("great", "rgeat") << endl;
    cout << solution.isScramble("great", "grate") << endl;
}
