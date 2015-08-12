/*=============================================================================
#     FileName: 74-SearchA2DMatrix.cpp
#         Desc: AC, 16ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-09 20:20:28
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        bool searchMatrix(vector<vector<int> >& matrix, int target) {
            if (matrix.empty() || matrix[0].empty()) {
                return false;
            }
            int m = matrix.size(), n = matrix[0].size(), i = 0, j = n - 1;
            while (i < m && j >= 0) {
                int num = matrix[i][j];
                if (num == target) {
                    return true;
                } else if (num > target) {
                    j --;
                } else {
                    i ++;
                }
            }
            return false;
        }
};
