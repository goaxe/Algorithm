/*=============================================================================
#     FileName: 122-BestTimeToBuyAndSellStockII.cpp
#         Desc: AC, 12ms
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-22 20:42:12
#      History:
=============================================================================*/

#include <leetcode.h>

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int len = prices.size(), pos = 0, result = 0;
            if (len < 2) {
                return 0;
            }
            vector<int> points;
            while (pos + 1 < len) {
                while (pos + 1 < len && prices[pos + 1] <= prices[pos]) {
                    pos ++;
                }
                points.push_back(prices[pos]);
                while (pos + 1 < len && prices[pos + 1] >= prices[pos]) {
                    pos ++;
                }
                points.push_back(prices[pos]);

            }
            for (int i = 0; i < (int) points.size(); i += 2) {
                result += points[i + 1] - points[i];
            }
            return result;
        }
};

int main() {
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    Solution solution;
    cout << solution.maxProfit(prices) << endl;

}
