/*=============================================================================
#     FileName: 8-StringToInteger.cpp
#         Desc: AC, 12ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-02 11:00:20
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    int myAtoi(string str) {
        while (str[0] == ' ') {
            str = str.substr(1, str.length() - 1);
        }
        bool negative = false;
        if (str[0] == '-') {
            negative = true;
            str = str.substr(1, str.length() - 1);
        } else if (str[0] == '+') {
            str = str.substr(1, str.length() - 1);
        }
        int len = str.length();
        long result = 0;
        for (int i = 0; i < len; i ++) {
            if (!isdigit(str[i])) {
                return negative ? -result : result;
            }
            result = result * 10 + (str[i] - '0');
            if (negative && result - 1 > INT_MAX) {
                return INT_MIN;
            } else if (!negative && result > INT_MAX) {
                return INT_MAX;
            }
        }
        return negative ? -result : result;
    }
};

int main() {
    Solution solution;
    cout << solution.myAtoi("  1389040") << endl;
    cout << solution.myAtoi("  -1283498") << endl;
    cout << solution.myAtoi(" 120398409201398") << endl;
    return 0;
}
