/*=============================================================================
#     FileName: 130-SurroundedRegions.cpp
#         Desc: AC, 32ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-29 15:33:49
#      History:
=============================================================================*/

#include <leetcode.h>

struct Positon {
    int i;
    int j;
    Positon(int i, int j) {
        this->i = i;
        this->j = j;
    }
    Positon* operator + (Positon *pos) {
        return new Positon(this->i + pos->i, this->j + pos->j);
    }

};

class Solution {
    public:
        bool isValid(vector<vector<char> > &board, Positon *pos) {
            int m = board.size(), n = board[0].size(), i = pos->i, j = pos->j;
            if (i < m && i > - 1 && j < n && j > -1 && board[i][j] == 'O') {
                return true;
            }
            return false;

        }
        void bfs(vector<vector<char> > &board, int i, int j) {
            queue<Positon *> posQueue;
            posQueue.push(new Positon(i, j));
            Positon *direction[4] = {
                new Positon(1, 0),
                new Positon(-1, 0),
                new Positon(0, -1),
                new Positon(0, 1)
            };
            
            while (!posQueue.empty()) {
                Positon *pos = posQueue.front();
                posQueue.pop();
                for (int i = 0; i < 4; i ++) {
                    Positon* nextPos = *pos + direction[i];
                    if (isValid(board, nextPos)) {
                        board[nextPos->i][nextPos->j] = 'D';
                        posQueue.push(nextPos);
                    }
                }
            }
        }
        void solve(vector<vector<char> >& board) {
            if (board.empty() || board[0].empty()) {
                return ;
            }
            int m = board.size(), n = board[0].size();
            for (int i = 0; i < m; i ++) {
                if (board[i][0] == 'O') {
                    board[i][0] = 'D';
                    bfs(board, i, 0);
                }
                if (board[i][n - 1] == 'O') {
                    board[i][n - 1] = 'D';
                    bfs(board, i, n - 1);
                }
            }
            for (int j = 1; j < n - 1; j ++) {
                if (board[0][j] == 'O') {
                    board[0][j] = 'D';
                    bfs(board, 0, j);
                }
                if (board[m - 1][j] == 'O') {
                    board[m - 1][j] = 'D';
                    bfs(board, m - 1, j);
                }
            }
            for (int i = 0; i < m; i ++) {
                for (int j = 0; j < n; j ++) {
                    if (board[i][j] == 'D') {
                        board[i][j] = 'O';
                    } else if (board[i][j] == 'O') {
                        board[i][j] = 'X';
                    }
                }
            }
        }
};
