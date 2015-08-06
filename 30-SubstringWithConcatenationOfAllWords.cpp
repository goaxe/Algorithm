/*=============================================================================
#     FileName: 30-SubstringWithConcatenationOfAllWords.cpp
#         Desc: AC, 48ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-05 09:22:31
#      History:
=============================================================================*/

#include <leetcode.h>
#include <unordered_set>

class Solution {
    public:
        bool isSameMap(map<string, int> map1, map<string, int> map2) {
            if (map1.size() != map2.size()) {
                return false;
            }
            for (map<string, int>::iterator it = map1.begin(); it != map1.end(); it ++) {
                string tmp = it->first;
                if (map2.find(tmp) == map2.end() || map1[tmp] != map2[tmp]) {
                    return false;
                }
            }
            return true;
        }
        vector<int> findSubstring(string s, vector<string>& words) {
            vector<int> result;
            if (words.empty()) {
                return result;
            }
            if (s.length() < words.size() * words[0].length()) {
                return result;
            }
            int sLen = s.length(), wSize = words.size(), wLen = words[0].length();
            map<string, int> wordCount;
            for (int i = 0; i < wSize; i ++) {
                if (wordCount.find(words[i]) != wordCount.end()) {
                    wordCount[words[i]] ++;
                } else {
                    wordCount.insert(pair<string, int>(words[i], 1));

                }
            }
            for (int i = 0; i < wLen; i ++) {
                map<string, int> tmpCount;
                int start = i, end = start;
                while (end <= sLen - wLen && start <= sLen - wSize * wLen) {
                    string tmp = s.substr(end, wLen);
                    if (wordCount.find(tmp) == wordCount.end()) {
                        start = end + wLen;
                        end = start;
                        tmpCount.clear();
                    } else {
                        if (tmpCount.find(tmp) == tmpCount.end()) {
                            tmpCount.insert(pair<string, int>(tmp, 1));
                        } else {
                            tmpCount[tmp] ++;
                        }
                        end += wLen;
                        if (end - start == wSize * wLen) {
                            if (isSameMap(wordCount, tmpCount)) {
                                result.push_back(start);
                            }
                            string x = s.substr(start, wLen);
                            tmpCount[x] --;
                            if (!tmpCount[x]) {
                                tmpCount.erase(x);
                            }
                            start += wLen;
                        }
                    }
                }
            }
            return result;
        }
        //AC, 680ms
        vector<int> findSubstringII(string s, vector<string>& words) {
            vector<int> result;
            if (words.empty()) {
                return result;
            }
            if (s.length() < words.size() * words[0].length()) {
                return result;
            }
            int sLen = s.length(), wSize = words.size(), wLen = words[0].length();
            map<string, int> wordCount;
            for (int i = 0; i < wSize; i ++) {
                if (wordCount.find(words[i]) != wordCount.end()) {
                    wordCount[words[i]] ++;
                } else {
                    wordCount.insert(pair<string, int>(words[i], 1));

                }
            }
            for (int i = 0; i < wLen; i ++) {
                int start = i, end = start;
                while (end <= sLen - wLen && start <= sLen - wSize * wLen) {
                    string tmp = s.substr(end, wLen);
                    if (wordCount.find(tmp) == wordCount.end()) {
                        start = end + wLen;
                        end = start;
                    } else {
                        end += wLen;
                        if (end - start == wSize * wLen) {
                            map<string, int> tmpCount;
                            for (int j = start; j < end; j += wLen) {
                                string x = s.substr(j, wLen);
                                if (tmpCount.find(x) != tmpCount.end()) {
                                    tmpCount[x] ++;
                                } else {
                                    tmpCount.insert(pair<string, int>(x, 1));
                                }
                            }
                            if (isSameMap(wordCount, tmpCount)) {
                                result.push_back(start);
                            }
                            start += wLen;
                        }
                    }
                }
            }
            return result;
        }
};

int main() {
    vector<string> words;
    words.push_back("foo");
    words.push_back("bar");
    /*    words.push_back("word");*/
    //words.push_back("good");
    //words.push_back("best");
    /*words.push_back("good");*/

    Solution solution;
    vector<int> result = solution.findSubstring("barfoothefoobarman", words);
    //vector<int> result = solution.findSubstring("wordgoodgoodgoodbestword", words);
    for (int i = 0; i < (int)result.size(); i ++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
