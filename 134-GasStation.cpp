/*=============================================================================
#     FileName: 134-GasStation.cpp
#         Desc: AC, 8ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Created: 2015-08-30 09:54:34
#      Version: 0.0.1
#   LastChange: 2015-08-30 09:54:34
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int len = gas.size();
            int sum = 0, total = 0, j = -1;
            for (int i = 0; i < len; i ++) {
                int diff = gas[i] - cost[i];
                total += diff;
                sum += diff;
                if (sum < 0) {
                    j = i;
                    sum = 0;
                }
            }
            return total < 0 ? -1 : j + 1;
        }
};
