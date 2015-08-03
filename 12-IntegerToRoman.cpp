/*=============================================================================
#     FileName: 12-IntegerToRoman.cpp
#         Desc: AC, 72ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-02 14:42:31
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    string intToRoman(int num) {
        map<int, string> numMap;
        numMap[1000] = "M";
        numMap[900] = "CM";
        numMap[500] = "D";
        numMap[400] = "CD";
        numMap[100] = "C";
        numMap[90] = "XC";
        numMap[50] = "L";
        numMap[40] = "XL";
        numMap[10] = "X";
        numMap[9] = "IX";
        numMap[5] = "V";
        numMap[4] = "IV";
        numMap[1] = "I";

        int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}, index = 0;
        string result = "";
        while (num) {
            while (num >= nums[index]) {
                result += numMap[nums[index]];
                num -= nums[index];
            }
            index ++;
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.intToRoman(12) << endl;
    cout << solution.intToRoman(123) << endl;
    return 0;

}
