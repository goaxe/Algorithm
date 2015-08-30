/*=============================================================================
#     FileName: 127-WordLadder.cpp
#         Desc: AC, 332ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-28 22:06:47
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
            if (beginWord == "" || endWord == "" || beginWord == endWord || beginWord.length() != endWord.length() || wordDict.empty()) {
                return 0;
            }
            queue<string> wordQueue;
            wordQueue.push(beginWord);
            int result = 0, qSize = 1;
            while (!wordQueue.empty()) {
                string word = wordQueue.front(), tmp = word;
                wordQueue.pop();
                for (int i = 0; i < (int)word.length(); i ++) {
                    for (char j = 'a'; j <= 'z'; j ++) {
                        if (j == word[i]) {
                            continue;
                        }
                        tmp[i] = j;
                        if (tmp == endWord) {
                            return result + 2;
                        }
                        if (wordDict.find(tmp) != wordDict.end()) {
                            wordQueue.push(tmp);
                            wordDict.erase(tmp);
                        }
                    }
                    tmp[i] = word[i];
                }
                qSize --;
                if (!qSize) {
                    qSize = wordQueue.size();
                    result ++;
                }
            }
            return 0;
        }
};

int main() {
    unordered_set<string> wordDict;
    wordDict.insert("hot");
    wordDict.insert("dot");
    wordDict.insert("dog");
    wordDict.insert("lot");
    wordDict.insert("log");
    /*    wordDict.insert("a");*/
    //wordDict.insert("b");
    /*wordDict.insert("c");*/

    Solution solution;
    cout << solution.ladderLength("hit", "cog", wordDict) << endl;
    //cout << solution.ladderLength("a", "c", wordDict) << endl;
    return 0;
}
