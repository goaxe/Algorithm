/*=============================================================================
#     FileName: 70-ClimbingStairs.cpp
#         Desc: AC, 0ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-09 16:09:15
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int climbStairs(int n) {
            vector<int> result(n + 1, 1);
            for (int i = 2; i <= n; i ++) {
                result[i] = result[i - 1] + result[i - 2];
            }
            return result[n];
        }
};
