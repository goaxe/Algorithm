/*=============================================================================
#     FileName: 51-N-Queens.cpp
#         Desc: AC, 12ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-08 12:03:51
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        vector<string> getSolution(vector<int> &position) {
            int size = position.size();
            vector<string> result(size, string(size, '.'));
            for (int i = 0; i < size; i ++) {
                result[i][position[i]] = 'Q';
            }
            return result;
        }
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
        void dfs(vector<int> position, int n, vector<vector<string> > &result) {
            int size = position.size();
            if (size == n) {
                result.push_back(getSolution(position));
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
        vector<vector<string> > solveNQueens(int n) {
            vector<vector<string> > result;
            vector<int> position;
            dfs(position, n, result);
            return result;
        }
};

int main() {
    Solution solution;
    vector<vector<string> > result = solution.solveNQueens(4);
    for (int i = 0; i < (int)result.size(); i ++) {
        for (int j = 0; j < (int)result[i].size(); j ++) {
            cout << result[i][j] << endl;
        }
        cout << endl;
    }
}
