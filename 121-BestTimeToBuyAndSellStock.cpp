/*=============================================================================
#     FileName: 121-BestTimeToBuyAndSellStock.cpp
#         Desc: AC, 8ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-22 20:37:06
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int len = prices.size(), curMin = INT_MAX , curMax = INT_MIN;
            if (len < 2) {
                return 0;
            }
            for (int i = 0; i < len; i ++) {
                curMin = min(curMin, prices[i]);
                curMax = max(prices[i] - curMin, curMax);
            }
            return curMax;
        }
};
