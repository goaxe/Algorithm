/*=============================================================================
#     FileName: 123-BestTimeToBuyAndSellStockIII.cpp
#         Desc: AC, 12ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-22 22:26:44
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int len = prices.size(), result = 0;
            if (len < 2) {
                return result;
            }
            int leftMin = prices[0], rightMax = prices[len - 1];
            vector<int> left(len, 0), right(len, 0);
            for (int i = 1; i < len; i ++) {
                leftMin = min(leftMin, prices[i]);
                left[i] = max(left[i - 1], prices[i] - leftMin);
            }
            for (int i = len - 2; i >= 0; i --) {
                rightMax = max(rightMax, prices[i]);
                right[i] = max(right[i + 1], rightMax - prices[i]);
            }
            for (int i = 0; i < len; i ++) {
                result = max(result, left[i] + right[i]);
            }
            return result;
        }
};

int main() {
    int nums[] = {2,1,2,0,1};
    vector<int> prices;
    for (int i = 0; i < 5; i ++) {
        prices.push_back(nums[i]);
    }
    Solution solution;
    cout << solution.maxProfit(prices) << endl;
}
