class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buying_price = prices[0];
        int curr_profit = 0;
        int max_profit = 0;
        for(int i =1;i<n;i++){
            if(prices[i] <= buying_price){
                buying_price = prices[i];
            }
            curr_profit = abs(buying_price - prices[i]);
            max_profit = max(max_profit,curr_profit);
        }
        return max_profit;
    }
};