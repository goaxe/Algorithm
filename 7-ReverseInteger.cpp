/*=============================================================================
#     FileName: 7-ReverseInteger.cpp
#         Desc: AC, 8ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-02 10:04:06
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    int reverse(int x) {
        if (x == 0) {
            return 0;
        }
        bool negative = false;
        long uX = 0;
        if (x < 0) {
            negative = true;
            uX = -1 * long(x);
        } else {
            uX = x;
        }
        string str = "";
        while (uX) {
            str += '0' + uX % 10;
            uX /= 10;
        }
        while (str[0] == '0') {
            str = str.substr(1, str.length() - 1);
        }
        long result = 0;
        int len = str.length();
        for (int i = 0; i < len; i ++) {
            result = result * 10 + (str[i] - '0');
            if ((negative && result - 1 > INT_MAX) || (!negative && result > INT_MAX)) {
                return 0;
            }
        }
        return negative ? -result : result;
    }
};

int main() {
    Solution solution;
    cout << solution.reverse(100001230) << endl;
    cout << solution.reverse(INT_MAX) << endl;

    cout << solution.reverse(-12348928) << endl;
}
