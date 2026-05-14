class Solution {
public:
    // int recursion(vector<int>&prices, int index){
        // cout<<index<<" ";
        // if(index>=prices.size()){
        //     return 0;
        // }
        // int profit = 0;
        // for(int i=index; i<prices.size(); i++){
        //     int buy =  -prices[i];
        //     int sell = recursion(prices, index+1) + prices[index] + buy; 
        //     profit = max(profit, sell);
        // }

        // return profit;
    // }
    int maxProfit(vector<int>& prices) {
        // int profit = 0;

        // for(int i=0; i<prices.size(); i++){
        //     int buy = (prices[i]-(2*prices[i]));
        //     for(int j=i+1; j<prices.size(); j++){
        //         int sell = buy + prices[j];
        //         profit = max(sell, profit);
        //     }
        // }

        // return profit;

        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(int i=0; i<prices.size(); i++){
            minPrice = min(minPrice, prices[i]);

            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};