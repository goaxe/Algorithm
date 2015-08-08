/*=============================================================================
#     FileName: 54-SpiralMatrix.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-08 13:18:13
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int> >& matrix) {
            vector<int> result;
            if (matrix.empty()) {
                return result;
            }
            int m = matrix.size(), n = matrix[0].size();
            int left = 0, right = n - 1, top = 0, bottom = m - 1;
            while (left <= right && top <= bottom) {
                if (left == right) {
                    for (int i = top; i <= bottom; i ++) {
                        result.push_back(matrix[i][left]);
                    }
                    break;
                }
                if (top == bottom) {
                    for (int i = left; i <= right; i ++) {
                        result.push_back(matrix[top][i]);
                    }
                    break;
                }
                for (int i = left; i < right; i ++) {
                    result.push_back(matrix[top][i]);
                }
                for (int i = top; i < bottom; i ++) {
                    result.push_back(matrix[i][right]);
                }
                for (int i = right; i > left; i --) {
                    result.push_back(matrix[bottom][i]);
                }
                for (int i = bottom; i > top; i --) {
                    result.push_back(matrix[i][left]);
                }
                left ++;
                right --;
                top ++;
                bottom --;
            }
            return result;
        }
};

int main() {
    int size = 3;
    vector<vector<int> > matrix(size, vector<int>(size, -1));
    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size; j ++) {
            matrix[i][j] = i * size + j + 1;
        }
    }
    Solution solution;
    vector<int> result = solution.spiralOrder(matrix);
    for (int i = 0; i < (int) result.size(); i ++) {
        cout << result[i] << " ";
    }
    cout << endl;
}
