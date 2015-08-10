/*=============================================================================
#     FileName: 73-SetMatrixZeroes.cpp
#         Desc: AC, 84ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-09 19:51:03
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        void setZeroes(vector<vector<int> >& matrix) {
            if (matrix.empty() || matrix[0].empty()) {
                return ;
            }
            int m = matrix.size(), n = matrix[0].size();
            bool row = false, col = false;
            for (int i = 0; i < m; i ++) {
                if (!matrix[i][0]) {
                    col = true;
                    break;
                }
            }
            for (int i = 0; i < n; i ++) {
                if (!matrix[0][i]) {
                    row = true;
                    break;
                }
            }
            for (int i = 1; i < m; i ++) {
                for (int j = 1; j < n; j ++) {
                    if (!matrix[i][j]) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
            for (int i = 1; i < m; i ++) {
                if (!matrix[i][0]) {
                    for (int j = 1; j < n; j ++) {
                        matrix[i][j] = 0;
                    }
                }
            }
            for (int i = 1; i < n; i ++) {
                if (!matrix[0][i]) {
                    for (int j = 1; j < m; j ++) {
                        matrix[j][i] = 0;
                    }
                }
            }
            if (row) {
                for (int i = 0; i < n; i ++) {
                    matrix[0][i] = 0;
                }
            }
            if (col) {
                for (int i = 0; i < m; i ++) {
                    matrix[i][0] = 0;
                }
            }
        }
};

int main() {
    //[[0,0,0,5],[4,3,1,4],[0,1,1,4],[1,2,1,3],[0,0,1,1]]
    vector<vector<int> > matrix(1, vector<int>(2, 0));
    matrix[0][1] = 1;
    Solution solution;
    solution.setZeroes(matrix);
}
