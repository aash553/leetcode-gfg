class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy_price = prices[0];
        int max_profit = 0;

        for(int i =0;i<n;i++){
            buy_price = min(buy_price, prices[i]);
            int curr_profit = abs(buy_price - prices[i]);
            max_profit = max(max_profit,curr_profit);
        }
        return max_profit;
    }
};