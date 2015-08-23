/*=============================================================================
#     FileName: 118-Pascal'sTriangle.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-22 20:07:45
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        vector<vector<int> > generate(int numRows) {
            vector<vector<int> > result;
            vector<int> ret;
            for (int i = 0; i < numRows; i ++) {
                ret.clear();
                if (i == 0) {
                    ret.push_back(1);
                    result.push_back(ret);
                } else if (i == 1) {
                    ret.push_back(1);
                    ret.push_back(1);
                    result.push_back(ret);
                } else {
                    ret.push_back(1);
                    for (int j = 0; j < (int) result[i - 1].size() - 1; j ++) {
                        ret.push_back(result[i - 1][j] + result[i - 1][j + 1]);
                    }
                    ret.push_back(1);
                    result.push_back(ret);
                }
            }
            return result;
        }
};
