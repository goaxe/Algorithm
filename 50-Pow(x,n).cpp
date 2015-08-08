/*=============================================================================
#     FileName: 50-Pow(x,n).cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-08 11:54:13
#      History:
=============================================================================*/

#include <leetcode.h>
class Solution {
    public:
        double myPow(double x, int n) {
            if (n == 0 || x == 1) {
                return 1;
            }
            if (x == -1) {
                return n % 2 ? -1 : 1;
            }

            if (n < 0) {
                if (n == INT_MIN) {
                    return 1.0 / (myPow(x, INT_MAX) * x);
                }
                return 1.0 / myPow(x, -n);
            }

            double tmp = myPow(x, n / 2);
            return tmp * tmp * (n % 2 ? x : 1);
        }
};

