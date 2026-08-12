class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy_price = INT_MAX;
        int profit = 0;
        int max_profit = 0;

        if(n==0) return 0;

        for(int i = 0;i<n;i++){
            buy_price = min(buy_price,prices[i]);
            profit = prices[i] - buy_price;
            max_profit = max(max_profit,profit);
        }
        return max_profit;
    }
};