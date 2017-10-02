class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int current = 0;
        int profit = 0;
        bool has = false;
        for(int i = 1; i < prices.size(); i++){
            if(has == false){
                if(prices[i] > prices[i-1]){
                    has = true;
                    current = prices[i-1];
                }
            }
            else{
                if(prices[i] < prices[i-1]){
                    has = false;
                    profit = profit + prices[i-1] - current;
                }
            }
        }
        if(has == true){
            profit = profit + prices[prices.size()-1] - current;
        }
        return profit;
    }
};