/*=============================================================================
#     FileName: 40-CombinationSumII.cpp
#         Desc: AC, 20ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-07 16:15:20
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        void dfs(vector<int> &candidates, vector<int> ret, int index, int deta, vector<vector<int> > &result) {
            if (deta == 0) {
                result.push_back(ret);
                return ;
            }
            int len = candidates.size();
            if (index == len || deta < candidates[index]) {
                return ;
            }
            int start = index;
            while (index + 1 < len && candidates[index + 1] == candidates[index]) {
                index ++;
            }
            dfs(candidates, ret, index + 1, deta, result);
            for (int i = 0; i < index - start + 1; i ++) {
                ret.push_back(candidates[index]);
                dfs(candidates, ret, index + 1, deta - (i + 1) * candidates[index], result);
            }
        }
        vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
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
    candidates.push_back(10);
    candidates.push_back(1);
    candidates.push_back(2);
    candidates.push_back(7);
    candidates.push_back(6);
    candidates.push_back(1);
    candidates.push_back(5);
    
    Solution solution;
    vector<vector<int> > result = solution.combinationSum2(candidates, 8);
    for (int i = 0; i < (int)result.size(); i ++) {
        for (int j = 0; j < (int)result[i].size(); j ++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
