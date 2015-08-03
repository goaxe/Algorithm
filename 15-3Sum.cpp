/*=============================================================================
#     FileName: 15-3Sum.cpp
#         Desc: AC, 52ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-02 16:04:03
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> ret(3, INT_MIN);
        int len = nums.size();
        if (len < 3) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 2; i ++) {
            if (result.size() > 0 && ret[0] == nums[i]) {
                continue;
            }
            ret[0] = nums[i];
            int left = i + 1, right = len - 1;
            while (left < right) {
                int lVal = nums[left], rVal = nums[right], sum = lVal + rVal + ret[0];
                if (sum == 0) {
                    if (lVal == ret[1] && rVal == ret[2]) {
                    } else {
                        ret[1] = lVal;
                        ret[2] = rVal;
                        result.push_back(ret);
                    }
                    while (left < right && nums[left] == nums[++left]) {
                    }
                    while (left < right && nums[right] == nums[--right]) {
                    }
                } else if (sum > 0) {
                    right --;
                } else {
                    left ++;
                }
            }
        }
        return result;
    }
};  

int main() {
    //int num[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    int num[] = {0, 0, 0};
    vector<int> nums;
    for (int i = 0; i < (int)(sizeof(num) / sizeof(int)); i ++) {
        nums.push_back(num[i]);
    }
    Solution solution;
    vector<vector<int> > result = solution.threeSum(nums);
    for (int i = 0; i < (int)result.size(); i ++) {
        for (int j = 0; j < (int)result[i].size(); j ++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;

}

