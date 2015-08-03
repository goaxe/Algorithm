/*=============================================================================
#     FileName: 16-3SumClosest.cpp
#         Desc: AC, 16ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-02 19:30:12
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            int len = nums.size(), deta = INT_MAX;
            if (len < 3) {
                return INT_MAX;
            }
            sort(nums.begin(), nums.end());

            for (int i = 0; i < len - 2; i ++) {
                int left = i + 1, right = len - 1;
                while (left < right) {
                    int sum = nums[i] + nums[left] + nums[right];
                    if (sum == target) {
                        return sum;
                    } else if (sum > target) {
                        if (abs(sum - target) < abs(deta)) {
                            deta = sum - target;
                        }
                        right --;
                    } else {
                        if (abs(sum - target) < abs(deta)) {
                            deta = sum - target;
                        }
                        left ++;
                    }
                }
            }
            return target + deta;
        }
};

int main() {
    int num[] = {-1, 2, 1, -4};
    vector<int> nums;
    for (int i = 0; i < (int)(sizeof(num) / sizeof(int)); i ++) {
        nums.push_back(num[i]);
    }
    Solution solution;
    cout << solution.threeSumClosest(nums, 1) << endl;
    return 0;
}
