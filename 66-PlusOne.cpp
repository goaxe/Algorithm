/*=============================================================================
#     FileName: 66-PlusOne.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-09 10:45:19
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int add(int a, int &b) {
            int sum = a + b;
            b = sum / 10;
            return sum % 10;
        }
        vector<int> plusOne(vector<int>& digits) {
            if (digits.empty()) {
                digits.push_back(1);
                return digits;
            }
            int len = digits.size(), a, b = 1;
            for (int i = len - 1; i >= 0; i --) {
                a = digits[i];
                digits[i] = add(a, b);
            }
            if (b != 0) {
                digits.insert(digits.begin(), b);
            }
            return digits;
        }
};
