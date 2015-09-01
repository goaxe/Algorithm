/*=============================================================================
#     FileName: 139-WordBreak.cpp
#         Desc: AC, 4ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Created: 2015-08-31 21:12:19
#      Version: 0.0.1
#   LastChange: 2015-08-31 21:12:19
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        bool wordBreak(string s, unordered_set<string>& wordDict) {
            int len = s.length();
            if (!len) {
                return true;
            }
            vector<bool> canBreak(len + 1, false);
            canBreak[0] = true;
            for (int i = 0; i < len; i ++) {
                for (int j = i; j >= 0; j --) {
                    if (wordDict.count(s.substr(j, i - j + 1)) && canBreak[j]) {
                        canBreak[i + 1] = true;
                        break;
                    }
                }
            }
            return canBreak[len];
        }
};

int main() {
    unordered_set<string> wordDict;
    wordDict.insert("leet");
    wordDict.insert("code");
    Solution solution;
    cout << solution.wordBreak("leetcode", wordDict) << endl;
    cout << solution.wordBreak("leetcodes", wordDict) << endl;


}
