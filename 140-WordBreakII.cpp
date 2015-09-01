/*=============================================================================
#     FileName: 140-WordBreakII.cpp
#         Desc: AC, 12ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Created: 2015-08-31 21:31:26
#      Version: 0.0.1
#   LastChange: 2015-08-31 21:31:26
#      History:
#               0.0.1 | Jian Huang | init
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        void dfs(string &ret, int index, string &s, vector<string> &result, unordered_set<string> &wordDict) {
            int len = s.length(), retLen = ret.length();
            if (index == len) {
                result.push_back(ret.substr(1));
                return ;
            }
            for (int i = index; i <len; i ++) {
                string tmp = s.substr(index, i - index + 1);
                if (wordDict.count(tmp)) {
                    ret += " " + tmp;
                    dfs(ret, i + 1, s, result, wordDict);
                    ret.erase(retLen, i - index + 2);
                }
            }
        }
        vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
            vector<string> result;
            string ret = "";
            if (s == "") {
                return result;
            }
            //use dp to pruning
            int len = s.length();
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
            if (!canBreak[len]) {
                return result;
            }
            dfs(ret, 0, s, result, wordDict);
            return result;
        }
};

int main() {
    unordered_set<string> wordDict;
    wordDict.insert("cat");
    wordDict.insert("cats");
    wordDict.insert("and");
    wordDict.insert("sand");
    wordDict.insert("dog");

    Solution solution;
    vector<string> result = solution.wordBreak("catsanddog", wordDict);
    for (auto str : result) {
        cout << str << " ";
    }
    cout << endl;
}
