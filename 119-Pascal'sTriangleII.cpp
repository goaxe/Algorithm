/*=============================================================================
#     FileName: 119-Pascal'sTriangleII.cpp
#         Desc: AC, 0ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-22 20:08:46
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int getNum(int m, int n) {
            if (n == 0) {
                return 1;
            }
            if (n > m / 2) {
                return getNum(m, m - n);
            }
            double result = 0;
            for (int i = 0; i < n; i ++) {
                result += log(m - i);
            }

            for (int i = 0; i < n; i ++) {
                result -= log(i + 1);
            }
            result = exp(result);
            return result - (int) result >= 0.5 ? (int) result + 1 : (int) result;
        }
        vector<int> getRow(int rowIndex) {
            vector<int> result;
            for (int i = 0; i < rowIndex + 1; i ++) {
                result.push_back(getNum(rowIndex, i));
            }
            for (int i = 0; i < rowIndex + 1; i ++) {
                cout << result[i] << " ";
            }
            cout << endl;
            return result;
        }
};

int main() {
    Solution solution;
/*    for (int i = 0; i < 6; i ++) {*/
        //solution.getRow(i);
    /*}*/
    solution.getRow(5);
}
