/*=============================================================================
#     FileName: 60-PermutationSequence.cpp
#         Desc: AC, 0ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-08 17:38:10
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        string getPermutation(int n, int k) {
            vector<int> deta(n + 1, 1);
            vector<bool> exist(n + 1, false);
            for (int i = 2; i <= n; i ++) {
                deta[i] = deta[i - 1] * i;
            }
            k --;
            string result = "";
            int index = n;
            while (k) {
                int tmp = k / deta[index - 1], count = 0;
                for (int i = 1; i <= n; i ++) {
                    if (!exist[i]) {
                        count ++;
                    }
                    if (count == tmp + 1) {
                        exist[i] = true;
                        result += '0' + i;
                        break;
                    }
                }
                k -= tmp * deta[index - 1];
                index --;
            }
            for (int i = 1; i <= n; i ++) {
                if (!exist[i]) {
                    result += '0' + i;
                }
            }
            return result;
        }
};

int main() {
    Solution solution;
    for (int i = 0; i < 6; i ++) {
        cout << solution.getPermutation(4, i + 1) << endl;
    }
    return 0;
}
