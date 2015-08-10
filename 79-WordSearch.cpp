/*=============================================================================
#     FileName: 79-WordSearch.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-10 10:50:01
#      History:
=============================================================================*/

#include <leetcode.h>

struct Position {
    int i;
    int j;
    Position(int i, int j) {
        this->i = i;
        this->j = j;
    }
};

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        if (word == "") {
            return true;
        }
        if (board.empty() || board[0].empty()) {
            return false;
        }
        unordered_set<Position*> visited;
        queue<Position*> bfs;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (word[0] == board[i][j]) {
                    visited.clear();
                    bfs.push(new Position(i, j));
                    while (!bfs.empty()) {
                        Position *pos = bfs.front();
                        bfs.pop();

                    }
                }
            }
        }

    }
};
