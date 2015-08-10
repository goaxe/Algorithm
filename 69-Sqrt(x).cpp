/*=============================================================================
#     FileName: 69-Sqrt(x).cpp
#         Desc: AC, 8ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-09 15:59:03
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int sqrtBinary(int x, long low, long high) {
            if (high - low < 2) {
                if (high * high > x) {
                    return low;
                }
                return abs(low * low - x) < abs(high * high - x) ? low : high;
            }
            long mid = (low + high) >> 1;
            if (mid * mid > x) {
                return sqrtBinary(x, low, mid - 1);
            } else if (mid * mid == x) {
                return mid;
            }
            return sqrtBinary(x, mid, high);
        }
        int mySqrt(int x) {
            if (x == 0 || x == 1) {
                return x;
            }
            return sqrtBinary(x, 1, x - 1);
        }
};

int main() {
    Solution solution;
    cout << solution.mySqrt(4) << endl;
    cout << solution.mySqrt(3) << endl;
}
