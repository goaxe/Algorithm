/*=============================================================================
#     FileName: 68-TextJustification.cpp
#         Desc: AC, 0ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-09 11:07:48
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            vector<string> result;
            if (words.empty()) {
                return result;
            }
            int len = words.size(), start = 0, end, wordSize, totalSize;
            string ret;
            while (start < len) {
                end = start;
                ret = words[start];
                wordSize = ret.length();
                totalSize = ret.length();
                while (end + 1 < len && int(totalSize + 1 + words[end + 1].length()) <= maxWidth) {
                    end ++;
                    wordSize += words[end].length();
                    totalSize += words[end].length() + 1;
                }
                if (end == start || end == len - 1) {
                    for (int i = start + 1; i <= end; i ++) {
                        ret += " ";
                        ret += words[i];
                    }
                    while ((int) ret.length() < maxWidth) {
                        ret += " ";
                    }
                } else {
                    int deta1 = (maxWidth - wordSize) / (end - start), deta2 = (maxWidth - wordSize) % (end - start);
                    string tmp1(deta1 + 1, ' '), tmp2(deta1, ' ');
                    for (int i = start + 1; i <= start + deta2; i ++) {
                        ret += tmp1;
                        ret += words[i];
                    }
                    for (int i = start + deta2 + 1; i <= end; i ++) {
                        ret += tmp2;
                        ret += words[i];
                    }
                }
                result.push_back(ret);
                start = end + 1;
            }
            return result;
        }
};

int main() {
    //string str[] = {"This", "is", "an", "example", "of", "text", "justification."};
    string str[] = {"a", "b", "c", "c", "e"};
    vector<string> words;
    for (int i = 0; i < 5; i ++) {
        words.push_back(str[i]);
    }
    Solution solution;
    vector<string> result = solution.fullJustify(words, 1);
    for (int i = 0; i < (int) result.size(); i ++) {
        cout << result[i] << endl;
    }
    return 0;
}
