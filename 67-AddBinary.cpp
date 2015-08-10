/*=============================================================================
#     FileName: 67-AddBinary.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-09 10:51:19
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        char add(char c1, char c2, char &c3) {
            int sum = (c1 - '0') + (c2 - '0') + (c3 - '0');
            c3 = '0' + sum / 2;
            return '0' + sum % 2;
        }

        string addBinary(string a, string b) {
            if (a.length() < b.length()) {
                a.swap(b);
            }
            int len1 = a.length(), len2 = b.length();
            string result = "";
            char c1, c2, c3 = '0';
            for (int i = 0; i < len2; i ++) {
                c1 = a[len1 - i - 1];
                c2 = b[len2 - i - 1];
                result = add(c1, c2, c3) + result;
            }
            for (int i = len1 - len2 - 1; i >= 0; i --) {
                c1 = a[i];
                result = add(c1, '0', c3) + result;
            }
            if (c3 != '0') {
                result = c3 + result;
            }
            return result;
        }
};

int main() {
    Solution solution;
    cout << solution.addBinary("11", "1") << endl;
}
