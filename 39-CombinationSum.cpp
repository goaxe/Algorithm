/*=============================================================================
#     FileName: 39-CombinationSum.cpp
#         Desc: AC, 32ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-07 09:35:30
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        void dfs(vector<int> &candidates, vector<int> ret, int index, int deta, vector<vector<int> > &result) {
            int len = candidates.size();
            if (deta == 0) {
                result.push_back(ret);
                return ;
            }
            if (index == len) {
                return ;
            }
            if (deta < candidates[index]) {
                return ;
            }
            dfs(candidates, ret, index + 1, deta, result);
            
            int count = deta / candidates[index];
            for (int i = 0; i < count; i ++) {
                deta -= candidates[index];
                ret.push_back(candidates[index]);
                dfs(candidates, ret, index + 1, deta, result);
            }
        }

        vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
            vector<vector<int> > result;
            vector<int> ret;
            if (candidates.empty()) {
                return result;
            }
            sort(candidates.begin(), candidates.end());
            dfs(candidates, ret, 0, target, result);
            return result;
        }

};

int main() {
    vector<int> candidates;
    candidates.push_back(1);
    Solution solution;
    vector<vector<int> > result = solution.combinationSum(candidates, 2);
    for (int i = 0; i < (int)result.size(); i ++) {
        for (int j = 0; j < (int)result[i].size(); j ++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
