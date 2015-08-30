/*=============================================================================
#     FileName: 125-ValidPalindrome.cpp
#         Desc: AC, 10ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-28 22:05:00
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        bool isPalindrome(string s) {
            if (s == "") {
                return true;
            }
            transform(s.begin(), s.end(), s.begin(), ::tolower);

            int len = (int)s.length();
            string tmp = "";
            for (auto c : s) {
                if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                    tmp += c;
                }
            }
            len = (int) tmp.length();
            int i = 0, j = len - 1;
            while (i < j) {
                if (tmp[i ++] != tmp[j --]) {
                    return false;
                }
            }
            return true;
        }
};
