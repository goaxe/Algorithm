/*=============================================================================
#     FileName: 59-SpiralMatrixII.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-08 16:41:31
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        vector<vector<int> > generateMatrix(int n) {
            vector<vector<int> > result(n, vector<int>(n, 0));
            int left = 0, right = n - 1, top = 0, bottom = n - 1, generator = 1;
            while (left <= right && top <= bottom) {
                if (left == right) {
                    for (int i = top; i <= bottom; i ++) {
                        result[left][i] = generator ++;
                    }
                    break;
                }
                for (int i = left; i < right; i ++) {
                    result[top][i] = generator ++;
                }
                for (int i = top; i < bottom; i ++) {
                    result[i][right] = generator ++;
                }
                for (int i = right; i > left; i --) {
                    result[bottom][i] = generator ++;
                }
                for (int i = bottom; i > top; i --) {
                    result[i][left] = generator ++;
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
    Solution solution;
    int size = 4;
    vector<vector<int> > result = solution.generateMatrix(size);
    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size; j ++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
