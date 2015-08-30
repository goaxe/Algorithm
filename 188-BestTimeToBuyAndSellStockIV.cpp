/*=============================================================================
#     FileName: 188-BestTimeToBuyAndSellStockIV.cpp
#         Desc: 
#       Author: Jian Huang
#        Email: huangjian1993@gmail.com
#     HomePage: https://cn.linkedin.com/in/huangjian1993
#      Version: 0.0.1
#   LastChange: 2015-08-22 22:44:48
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
        int maxProfit(int k, vector<int>& prices) {
            int len = prices.size();
            if (len < 2 || k < 1) {
                return 0;
            }
            if (k >= len) {
                return maxProfit(prices);
            }
            //local ith day j transactions and the last day mast transact
            //global ith day most j transactions
            vector<vector<int> > local(len, vector<int>(k + 1)), global(len, vector<int>(k + 1));
            for (int i = 1; i < len; i ++) {
                int diff = prices[i] - prices[i - 1];
                for (int j = 1; j <= k; j ++) {
                    local[i][j] = max(local[i - 1][j] + diff, global[i - 1][j - 1] + max(diff, 0));
                    global[i][j] = max(global[i - 1][j], local[i][j]);
                }
            }
            return global[len - 1][k];

        }
};

int main() {
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(2);
    Solution solution;
    cout << solution.maxProfit(1, prices) << endl;

}
