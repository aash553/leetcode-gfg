class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_price = prices[0];
        int cur_profit = 0;
        int max_profit = 0;

        for(int i =1;i<prices.size();i++){
            if(buy_price>prices[i]){
                buy_price = prices[i];
            }else{
                cur_profit = prices[i]-buy_price;
                max_profit = max(max_profit,cur_profit);
            } 
        }
        return max_profit;
    }
};