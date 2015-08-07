/*=============================================================================
#     FileName: 37-SudokuSolver.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-06 22:27:59
#      History:
=============================================================================*/

#include <leetcode.h>

void print(vector<vector<char> > &board) {
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

class Solution {
    public:
        bool isValidSudoku(vector<vector<char> > &board) {
            for (int i = 0; i < 9; i ++) {
                vector<bool> exist(9, false);
                for (int j = 0; j < 9; j ++) {
                    if (board[i][j] == '.') {
                        continue;
                    }
                    if (exist[board[i][j] - '1']) {
                        return false;
                    }
                    exist[board[i][j] - '1'] = true;
                }
            }
            for (int j = 0; j < 9; j ++) {
                vector<bool> exist(9, false);
                for (int i = 0; i < 9; i ++) {
                    if (board[i][j] == '.') {
                        continue;
                    }
                    if (exist[board[i][j] - '1']) {
                        return false;
                    }
                    exist[board[i][j] - '1'] = true;
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
                        if (exist[board[m][n] - '1']) {
                            return false;
                        }
                        exist[board[m][n] - '1'] = true;
                    }
                }
            }
            return true;
        }

        bool isValidSudoku(vector<vector<char> > &board, int i, int j) {
            bool exist[9];
            memset(exist, false, sizeof(exist));
            for (int k = 0; k < 9; k ++) {
                if (board[i][k] != '.') {
                    if (exist[board[i][k] - '1']) {
                        return false;
                    }
                    exist[board[i][k] - '1'] = true;
                }
            }
            memset(exist, false, sizeof(exist));
            for (int k = 0; k < 9; k ++) {
                if (board[k][j] != '.') {
                    if (exist[board[k][j] - '1']) {
                        return false;
                    }
                    exist[board[k][j] - '1'] = true;
                }
            }
            memset(exist, false, sizeof(exist));
            int m = i / 3, n = i / 3;
            for (int x = m; x < m + 3; x ++) {
                for (int y = n; y < n + 3; y ++) {
                    if (board[x][y] != '.') {
                        if (exist[board[x][y] - '1']) {
                            return false;
                        }
                        exist[board[x][y] - '1'] = true;
                    }
                }
            }
            return true;
        }
        bool solve(vector<vector<char> > &board, int i, int j) {
            cout << i << " " << j << endl;
            print(board);
            if (i == 9) {
                return true;
            }
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c ++) {
                    board[i][j] = c;
                    if (isValidSudoku(board, i, j)) {
                        int nextI = j == 8 ? i + 1 : i, nextJ = j == 8 ? 0 : j + 1;
                        if (solve(board, nextI, nextJ)) {
                            return true;
                        }

                    }
                    board[i][j] = '.';
                }
            } else {
                int nextI = j == 8 ? i + 1 : i, nextJ = j == 8 ? 0 : j + 1;
                return solve(board, nextI, nextJ);
            }
            return false;
        }
        void solveSudoku(vector<vector<char> >& board) {
            solve(board, 0, 0);
        }
};

int main() {
    string str[] = {
        ".....7..9",
        ".4..812..",
        "...9...1.",
        "..53...72",
        "293....5.",
        ".....53..",
        "8...23...",
        "7...5..4.",
        "531.7...."
    };
    vector<vector<char> > board(9, vector<char>(9, '0'));
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            board[i][j] = str[i][j];
        }
    }
    Solution solution;
    solution.solveSudoku(board);
    print(board);
}
