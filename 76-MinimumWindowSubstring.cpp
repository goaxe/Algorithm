/*=============================================================================
#     FileName: 76-MinimumWindowSubstring.cpp
#         Desc: AC, 16ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-09 21:30:47
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        string minWindow(string s, string t) {
            int len1 = s.length(), len2 = t.length(), start = 0, end = 0, count = 0, minLen = INT_MAX, minIndex;
            vector<int> needCount(256, 0), findCount(256, 0);
            if (len2 == 0 || len1 < len2) {
                return "";
            }
            for (int i = 0; i < len2; i ++) {
                needCount[int(t[i])] ++;
            }
            for (; end < len1; end ++) {
                int index = (int)s[end];
                if (!needCount[index]) {
                    continue;
                }
                findCount[index] ++;
                if (findCount[index] <= needCount[index]) {
                    count ++;
                }
                if (count == len2) {
                    while (start < end) {
                        int index = (int)s[start];
                        if (!needCount[index]) {
                            start ++;
                            continue;
                        }
                        if (findCount[index] > needCount[index]) {
                            findCount[index] --;
                            start ++;
                            continue;
                        } else {
                            break;
                        }
                    }
                    if (minLen > end - start + 1) {
                        minLen = end - start + 1;
                        minIndex = start;
                    }
                }
            }
            if (minLen == INT_MAX) {
                return "";
            }
            return s.substr(minIndex, minLen);
        }
        //AC, 200ms
        string minWindowI(string s, string t) {
            if (t == "" || s.length() < t.length()) {
                return "";
            }
            int len1 = s.length(), len2 = t.length(), start = 0, end = 0, minLen = INT_MAX, minIndex = -1;
            map<char, int> tMap;
            map<char, int> sMap;
            for (int i = 0; i < len2; i ++) {
                char c = t[i];
                if (tMap.find(c) == tMap.end()) {
                    tMap.insert(pair<char, int>(c, 1));
                } else {
                    tMap[c] ++;
                }
            }
            sMap = tMap;
            while (end < len1) {
                char c = s[end];
                if (sMap.find(c) == sMap.end()) {
                } else {
                    sMap[c] --;
                    if (sMap[c] == 0) {
                        sMap.erase(c);
                        if (sMap.empty()) {
                            break;
                        }
                    }
                }
                end ++;
            }
            if (end == len1) {
                return "";
            }
            minLen = end - start + 1;
            minIndex = 0;
            sMap.clear();
            for (int i = 0; i <= end; i ++) {
                char c = s[i];
                if (sMap.find(c) == sMap.end()) {
                    sMap.insert(pair<char, int>(c, 1));
                } else {
                    sMap[c] ++;
                }
            }
            while (true) {
                char miss;
                while (true) {
                    if (start > end) {
                        break;
                    }
                    char c = s[start];
                    if (tMap.find(c) == tMap.end() || sMap[c] > tMap[c]) {
                        start ++;
                        sMap[c] --;
                    } else if (sMap[c] == tMap[c]) {
                        miss = c;
                        if (minLen > end -start + 1) {
                            minLen = end - start + 1;
                            minIndex = start;
                        }
                        start ++;
                        sMap[c] --;
                        break;
                    } else {
                    }
                }
                if (start > end || end == len1 - 1) {
                    break;
                }
                while (end + 1 < len1 && s[end + 1] != miss) {
                    end ++;
                    char c = s[end];
                    if (sMap.find(c) == sMap.end()) {
                        sMap.insert(pair<char, int>(c, 1));
                    } else {
                        sMap[c] ++;
                    }
                }
                if (end + 1 == len1) {
                    break;
                }
                end ++;
                sMap[miss] ++;
            }
            return s.substr(minIndex, minLen);
        }
};

int main() {
    Solution solution;
    cout << solution.minWindowI("a", "b") << endl;
/*    cout << solution.minWindow("cabefgecdaecf", "cae") << endl;*/
    //cout << endl;
    //cout << solution.minWindow("adobecodebanc", "abcda") << endl;
    //cout << endl;
    //cout << solution.minWindow("abc", "adc") << endl;
    //cout << endl;
    //cout << solution.minWindow("ab", "b") << endl;
    //cout << endl;
    /*cout << solution.minWindow("bdab", "ab") << endl;*/
}
