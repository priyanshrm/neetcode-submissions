class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_price = INT_MAX;
        int profit = 0;
        for(auto price: prices){
            if(price < buy_price){
                buy_price = price;
                continue;
            }
            profit = max(profit, price - buy_price);
        }
        return profit;
    }
};
