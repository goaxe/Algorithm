/*=============================================================================
#     FileName: 96-UniqueBinarySearchTrees.cpp
#         Desc: AC, 0ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-19 07:14:33
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int numTrees(int n) {
            vector<int> result(n + 1, 1);
            for (int i = 2; i <= n; i ++) {
                result[i] = 0;
                for (int j = 0; j < i; j ++) {
                    result[i] += result[j] * result[i - 1 - j];
                }
            }
            return result[n];
        }
};

int main() {
    Solution solution;
    cout << solution.numTrees(3) << endl;
}
