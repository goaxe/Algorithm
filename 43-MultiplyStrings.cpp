/*=============================================================================
#     FileName: 43-MultiplyStrings.cpp
#         Desc: AC, 116ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-07 18:10:47
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        char add(char a, char b, char &c) {
            int sum = (a - '0') + (b - '0') + (c - '0');
            c = '0' + sum / 10;
            return '0' + sum % 10;
        }
        string add(string num1, string num2) {
            if (num1.length() < num2.length()) {
                num1.swap(num2);
            }
            char c = '0';
            string result = "";
            int len1 = num1.length(), len2 = num2.length();
            for (int i = 0; i < len2; i ++) {
                char a = num1[len1 - i - 1], b = num2[len2 - i - 1];
                result = add(a, b, c) + result;
            }
            for (int i = len1 - len2 - 1; i >= 0; i --) {
                result = add(num1[i], '0', c) + result;
            }
            if (c != '0') {
                result = c + result;
            }
            return result;
        }
        char  multiply(char a, char b, char &c) {
            int result = (a - '0') * (b - '0') + (c - '0');
            c = '0' + result / 10;
            return '0' + result % 10;
        }
        string multiply(char a, string num) {
            int len = num.length();
            char c = '0';
            string result = "";
            for (int i = 0; i < len; i ++) {
                char b = num[len - i - 1];
                result = multiply(a, b, c) + result;
            }
            if (c != '0') {
                result = c + result;
            }
            return result;
        }
        string multiply(string num1, string num2) {
            string result = "";
            int len = num2.length();
            for (int i = 0; i < len; i ++) {
                string tmp = multiply(num2[len - i - 1], num1);
                for (int j = 0; j < i; j ++) {
                    tmp += '0';
                }
                result = add(tmp, result);
            }
            while (result != "" && result[0] == '0') {
                result = result.substr(1, result.length() - 1);
            }
            return result == "" ? "0" : result;
        }
};

int main() {
    Solution solution;
    cout << solution.multiply("110", "11") << endl;
    return 0;
}
