class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_price = prices[0];
        int curr_profit = prices[0];
        int max_profit = INT_MIN;

        for(int i = 0;i<prices.size(); i++){
            if(buy_price > prices[i]){
                buy_price = prices[i];
            }
            curr_profit = abs(buy_price-prices[i]);
            max_profit = max(max_profit , curr_profit);
        }
        return max_profit;
    }
};