/*=============================================================================
#     FileName: 52-N-QueensII.cpp
#         Desc: AC, 12ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-08 12:28:33
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        bool validPosition(vector<int> &position) {
            int size = position.size(), val = position[size - 1];
            for (int i = 0; i < size - 1; i ++) {
                int tmp = position[i];
                if (tmp == val || tmp + i == val + size - 1 || i - tmp == size - 1 - val) {
                    return false;
                }
            }
            return true;
        }
        void dfs(vector<int> position, int n, int &result) {
            int size = position.size();
            if (size == n) {
                result ++;
                return ;
            }
            position.push_back(-1);
            for (int i = 0; i < n; i ++) {
                position[size] = i;
                if (validPosition(position)) {
                    dfs(position, n, result);
                }
            }
        }
        int totalNQueens(int n) {
            int result = 0;
            vector<int> position;
            dfs(position, n, result);
            return result;
        }
};

int main() {
    Solution solution;
    cout << solution.totalNQueens(4) << endl;
    return 0;
}
