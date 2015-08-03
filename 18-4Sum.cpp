/*=============================================================================
#     FileName: 18-4Sum.cpp
#         Desc: AC, 104ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-02 20:11:26
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        vector<vector<int> > fourSum(vector<int>& nums, int target) {
            vector<vector<int> > result;
            vector<int> ret(4, INT_MAX);
            int len = nums.size();
            if (len < 4) {
                return result;
            }
            sort(nums.begin(), nums.end());
            for (int i = 0; i < len - 3; i ++) {
                if (result.size() > 0 && ret[0] == nums[i]) {
                    continue;
                }
                for (int j = i + 1; j < len - 2; j ++) {
                    if (result.size() > 0 && ret[0] == nums[i] && ret[1] == nums[j]) {
                        continue;
                    }
                    ret[0] = nums[i];
                    ret[1] = nums[j];
                    int left = j + 1, right = len - 1;
                    while (left < right) {
                        int lVal = nums[left], rVal = nums[right], deta = ret[0] + ret[1] + lVal + rVal - target;
                        if (deta == 0) {
                            ret[2] = lVal;
                            ret[3] = rVal;
                            result.push_back(ret);
                            while (left < right && nums[left] == nums[++left]) {}
                            while (left < right && nums[right] == nums[--right]) {}
                        } else if (deta > 0) {
                            right --;
                        } else {
                            left ++;
                        }
                    }
                }
            }
            return result;
        }
};

int main() {
    int num[] = {-1,-5,-5,-3,2,5,0,4};
    vector<int> nums;
    for (int i = 0; i < (int)(sizeof(num)/sizeof(int)); i ++) {
        nums.push_back(num[i]);
    }
    Solution solution;
    vector<vector<int> > result = solution.fourSum(nums, -7);
    for (int i = 0; i < (int)result.size(); i ++) {
        for (int j = 0; j < (int)result[i].size(); j ++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
