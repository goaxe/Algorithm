/*=============================================================================
#     FileName: 120-Triangle.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-22 20:27:41
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int minimumTotal(vector<vector<int> >& triangle) {
            if (triangle.empty()) {
                return 0;
            }
            int len = triangle.size();
            vector<int> result = triangle[len - 1];
            for (int i = len - 2; i >= 0; i --) {
                for (int j = 0; j <= i; j ++) {
                    result[j] = min(result[j], result[j + 1]) + triangle[i][j];
                }
            }
            return result[0];
        }
};
