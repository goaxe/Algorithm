/*=============================================================================
#     FileName: 37-SudokuSolver.cpp
#         Desc: AC, 80ms
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
        bool isValidSudoku(vector<vector<char> > &board, int i, int j) {
            //only need to compare with baord[i][j]
            for (int k = 0; k < 9; k ++) {
                if (k != j && board[i][k] == board[i][j]) {
                    return false;
                }
            }
            for (int k = 0; k < 9; k ++) {
                if (k != i && board[k][j] == board[i][j]) {
                    return false;
                }
            }
            int m = i / 3, n = j / 3;
            for (int x = 3 * m; x < 3 * m + 3; x ++) {
                for (int y = 3 * n; y < 3 *n + 3; y ++) {
                    if (/*(x != i || y != j)*/x != i && y != j && board[x][y] == board[i][j]) {
                        return false;
                    }
                }
            }
            return true;
        }
        bool solve(vector<vector<char> > &board) {
            //print(board);
            for (int i = 0; i < 9; i ++) {
                for (int j = 0; j < 9; j ++) {
                    if (board[i][j] == '.') {
                        cout << i << " " << j << endl;
                        print(board);
                        for (char c = '1'; c <= '9'; c ++) {
                            board[i][j] = c;
                            if (isValidSudoku(board, i, j)) {
                                if (solve(board)) {
                                    return true;
                                }
                            } else {
                            }
                            board[i][j] = '.';
                        }
                        return false; // this is very important!
                    }
                }
            }
            return true;//this needs to be true
        }
        void solveSudoku(vector<vector<char> >& board) {
            solve(board);
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
