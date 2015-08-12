/*=============================================================================
#     FileName: 79-WordSearch.cpp
#         Desc: AC, 52ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-10 10:50:01
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    bool search(vector<vector<char> > &board, string word, int i, int j, vector<vector<bool> > &visited) {
        if (word == "") {
            return true;
        }
        int m = board.size(), n = board[0].size();
        int directions[][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1},
        };
        for (int k = 0; k < 4; k ++) {
            int nI = i + directions[k][0], nJ = j + directions[k][1];
            if (nI >= 0 && nI < m && nJ >= 0 && nJ < n && !visited[nI][nJ] && board[nI][nJ] == word[0]) {
                visited[nI][nJ] = true;
                if (search(board, word.substr(1), nI, nJ, visited)) {
                    visited[nI][nJ] = false;
                    return true;
                }
                visited[nI][nJ] = false;
            }
        }
        return false;
    }

    bool exist(vector<vector<char> >& board, string word) {
        if (word == "") {
            return true;
        }
        if (board.empty() || board[0].empty()) {
            return false;
        }
        int m = board.size(), n = board[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (word.length() == 1 || search(board, word.substr(1), i, j, visited)) {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};

int main() {
    string strs[] = {"ABCE", "SFCS", "ADEE"};
    vector<vector<char> > board(3, vector<char>(4, 'a'));
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 4; j ++) {
            board[i][j] = strs[i][j];
        }
    }
    Solution solution;
    cout << solution.exist(board, "ABCCED") << endl;
    cout << solution.exist(board, "SEE") << endl;
    cout << solution.exist(board, "ABCB") << endl;
}
