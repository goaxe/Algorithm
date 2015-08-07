/*=============================================================================
#     FileName: 36-ValidSudoku.cpp
#         Desc: AC, 16ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-06 22:17:45
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        bool isValidSudoku(vector<vector<char> >& board) {
            for (int i = 0; i < 9; i ++) {
                vector<bool> exist(9, false);
                for (int j = 0; j < 9; j ++) {
                    if (board[i][j] == '.') {
                        continue;
                    }
                    if (exist[board[i][j] - '0']) {
                        return false;
                    }
                    exist[board[i][j] - '0'] = true;
                }
            }
            for (int j = 0; j < 9; j ++) {
                vector<bool> exist(9, false);
                for (int i = 0; i < 9; i ++) {
                    if (board[i][j] == '.') {
                        continue;
                    }
                    if (exist[board[i][j] - '0']) {
                        return false;
                    }
                    exist[board[i][j] - '0'] = true;
                }
            }

            for (int i = 0; i < 9; i += 3) {
                for (int j = 0; j < 9; j += 3) {
                    vector<bool> exist(9, false);
                    for (int k = 0; k < 9; k ++) {
                        int m = i + k / 3, n = j + k % 3;
                        if (board[m][n] == '.') {
                            continue;
                        }
                        if (exist[board[m][n] - '0']) {
                            return false;
                        }
                        exist[board[m][n] - '0'] = true;
                    }
                }
            }

            return true;
        }
};
