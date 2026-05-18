class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy_price = prices[0];
        int max_profit = 0;

        for(int i=1;i<n;i++){
            buy_price = min(buy_price,prices[i]);
            int profit = abs(buy_price - prices[i]);
            max_profit = max(profit,max_profit);
        }
        return max_profit;
    }
};