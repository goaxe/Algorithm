/*=============================================================================
#     FileName: 77-Combinations.cpp
#         Desc: AC, 24ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-10 09:44:13
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        void dfs(vector<int> ret, int level, int n, int k, vector<vector<int> > &result) {
            int len = ret.size();
            if (len == k) {
                result.push_back(ret);
                return ;
            }
            if (level > n) {
                return ;
            }
            dfs(ret, level + 1, n, k, result);
            ret.push_back(level);
            dfs(ret, level + 1, n, k, result);
        } 
        vector<vector<int> > combine(int n, int k) {
            vector<vector<int> > result;
            vector<int> ret;
            if (n < 1 || n < k) {
                return result;
            }
            dfs(ret, 1, n, k, result);
            return result;
        }
};

int main() {
    Solution solution;
    vector<vector<int> > result = solution.combine(4, 2);
    for (int i = 0; i < (int) result.size(); i ++) {
        for (int j = 0; j < (int) result[i].size(); j ++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    } 
    return 0;
}
