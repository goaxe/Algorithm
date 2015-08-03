/*=============================================================================
#     FileName: 29-DivideTwoIntegers.cpp
#         Desc: AC, 8ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-04 07:42:16
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    int divideLong(long &uDivident, long uDivisor) {
        int result = 1;
        while (uDivisor * 10 < uDivident) {
            uDivisor *= 10;
            result *= 10;
        }
        uDivident -= uDivisor;
        return result;
    }
    int divide(int dividend, int divisor) {
        if (!dividend) {
            return 0;
        }
        if (!divisor) {
            return INT_MAX;
        }
        bool negative = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
        long uDivident = dividend > 0 ? dividend : -1 * (long)dividend;
        long uDivisor = divisor > 0 ? divisor : -1 * (long)divisor;
        long result = 0;
        while (uDivident >= uDivisor) {
            result += divideLong(uDivident, uDivisor);
        }
        return negative ? (result - 1 > INT_MAX ? INT_MIN : -result) : (result > INT_MAX ? INT_MAX : result);
    }
};

int main() {
    Solution solution;
    cout << solution.divide(1025, 25) << endl;
    return 0;
}

