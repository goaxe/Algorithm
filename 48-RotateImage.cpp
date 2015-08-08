/*=============================================================================
#     FileName: 48-RotateImage.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-08 10:30:54
#      History:
=============================================================================*/

#include <leetcode.h>

void print(vector<vector<int> > &matrix) {
    for (int i = 0; i < (int)matrix.size(); i ++) {
        for (int j = 0; j < (int)matrix[i].size(); j ++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
class Solution {
    public:
        void rotate(vector<vector<int> > &matrix) {
            if (matrix.empty()) {
                return ;
            }
            int size = matrix.size();
            print(matrix);
            for (int i = 0; i < size / 2; i ++) {
                for (int j = i; j < size - i - 1; j ++) {
                    int tmp = matrix[i][j];
                    matrix[i][j] = matrix[size - j - 1][i];
                    matrix[size - j - 1][i] = matrix[size - i - 1][size - j - 1];
                    matrix[size - i - 1][size - j - 1] = matrix[j][size - i - 1];
                    matrix[j][size - i - 1] = tmp;
                }
            }
            print(matrix);
        }
};

int main() {
    int size = 3;
    vector<vector<int> > matrix(size, vector<int>(size, 0));
    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size; j ++) {
            matrix[i][j] = i * size + j;
        }
    }
    Solution solution;
    solution.rotate(matrix);
    return 0;
}
