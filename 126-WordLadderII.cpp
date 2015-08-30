/*=============================================================================
#     FileName: 126-WordLadderII.cpp
#         Desc: AC, 368ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-29 09:59:20
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int ladderLength(string beginWord, string endWord, unordered_set<string> wordDict) {
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
        void dfs(vector<string> &ret, int minLen, string &end, unordered_set<string> &dict, vector<vector<string> > &result) {
            int len = ret.size(), wordLen = end.length();
            if (len == minLen) {
                return ;
            }
            string word = ret.back(), tmp = word;
            for (int i = 0; i < wordLen; i ++) {
                for (char j = 'a'; j <= 'z'; j ++) {
                    if (j == word[i]) {
                        continue;
                    }
                    tmp[i] = j;
                    if (tmp == end) {
                        ret.push_back(tmp);
                        result.push_back(ret);
                        ret.pop_back();
                        continue;
                    }
                    if (dict.find(tmp) != dict.end()) {
                        ret.push_back(tmp);
                        dict.erase(tmp);
                        dfs(ret, minLen, end, dict, result);
                        dict.insert(tmp);
                        ret.pop_back();
                    }
                }
                tmp[i] = word[i];
            }
        }
        vector<vector<string> > findLaddersII(string start, string end, unordered_set<string> &dict) {
            vector<vector<string> > result;
            vector<string> ret;
            int minLen = ladderLength(start, end, dict);
            if (!minLen) {
                return result;
            }
            ret.push_back(start);
            dfs(ret, minLen, end, dict, result);
            return result;
        }

        void generateResult(unordered_map<string, unordered_set<string> > &prevMap, vector<string> &ret, const string &word, vector<vector<string> > &result) {
            if (prevMap[word].size() == 0) {
                ret.push_back(word);
                vector<string> path = ret;
                reverse(path.begin(), path.end());
                result.push_back(path);
                ret.pop_back();
                return ;
            }
            ret.push_back(word);
            for (auto it = prevMap[word].begin(); it != prevMap[word].end(); it ++) {
                generateResult(prevMap, ret, *it, result);
            }
            ret.pop_back();
        }
        //prev map is excellent
        vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
            vector<vector<string> > result;
            vector<string> ret;
            unordered_map<string, unordered_set<string> > prevMap;
            vector<unordered_set<string> > candidates(2);
            candidates[0].insert(start);
            while (true) {
/*                for (auto it = candidates[0].begin(); it != candidates[0].end(); it ++) {*/
                    //cout << *it << " ";
                //}
                //cout << endl;
                //for (auto it = dict.begin(); it != dict.end(); it ++) {
                    //cout << *it << " ";
                //}
                /*cout << endl;*/
                for (auto it = candidates[0].begin(); it != candidates[0].end(); it ++) {
                    dict.erase(*it);
                }
                candidates[1].clear();
                for (auto it = candidates[0].begin(); it != candidates[0].end(); it ++) {
                    for (int i = 0; i < (int) it->length(); i ++) {
                        string word = *it;
                        for (char j = 'a'; j <= 'z'; j ++) {
                            if (word[i] == j) {
                                continue;
                            }
                            word[i] = j;
                            if (dict.find(word) != dict.end()) {
                                prevMap[word].insert(*it);
                                candidates[1].insert(word);
                            }
                            if (word == end) {
                                prevMap[word].insert(*it);
                                candidates[1].insert(word);

                            }
                        }
                    }
                }
                if (candidates[1].empty()) {
                    return result;
                }
                if (candidates[1].count(end)) {
                    break;
                }
                candidates[0].swap(candidates[1]);
            }
            cout << "fuck" << endl;
            generateResult(prevMap, ret, end, result);
            return result;
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
    vector<vector<string> > result = solution.findLadders("hit", "cog", wordDict);
    cout << "result: " << result.size() << endl;
    for (int i = 0; i < (int) result.size(); i ++) {
        for (int j = 0; j < (int) result[i].size(); j ++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    //cout << solution.ladderLength("a", "c", wordDict) << endl;
    return 0;
}
