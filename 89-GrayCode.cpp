/*=============================================================================
#     FileName: 89-GrayCode.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-18 07:37:37
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        vector<int> grayCode(int n) {
            if (n == 0) {
                vector<int> result;
                result.push_back(0);
                return result;
            }
            if (n == 1) {
                vector<int> result;
                result.push_back(0);
                result.push_back(1);
                return result;
            }
            vector<int> ret = grayCode(n - 1), result(ret.size() * 2, 0);
            for (int i = 0; i < (int) ret.size(); i += 2) {
                result[2 * i] = ret[i] << 1;
                result[2 * i + 1] = (ret[i] << 1) + 1;
                result[2 * i + 2] = (ret[i + 1] << 1) + 1;
                result[2 * i + 3] = ret[i + 1] << 1;
            }
            return result;
        }
};

int main() {
    Solution solution;
    vector<int> result = solution.grayCode(2);
    for (int i = 0; i < (int) result.size(); i ++) {
        cout << result[i] << " ";
    }
    cout << endl;
}
