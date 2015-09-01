/*=============================================================================
#     FileName: 136-SingleNumber.cpp
#         Desc: AC, 20ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Created: 2015-08-31 19:43:24
#      Version: 0.0.1
#   LastChange: 2015-08-31 19:43:24
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int result = 0;
            for (auto num : nums) {
                result ^= num;
            }
            return result;
        }
};
