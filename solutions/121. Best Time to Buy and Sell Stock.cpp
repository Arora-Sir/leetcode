class Solution {
public:
    int maxProfit(vector<int>& prices) {
​
        int current_price = INT_MAX;
        int profit =0;
        if(prices.size()==1) return 0;
        else{
            for(int i=0;i<prices.size();i++){
                current_price = min (current_price,prices[i]);
                profit = max(profit, prices[i]- current_price);
                }   
            return profit;
            }
        
        
        
//Running little slow (i've done)
//         int n = prices.size();
//         int purchase_at = prices[0];
//         int profit = INT_MIN;
//         int sell = INT_MIN;
        
//         if(n==1) return 0;
//         else{
//                     for(int i=1;i<n;i++){
//                 if(purchase_at > prices[i]) purchase_at = prices[i];
//                 else{sell = prices[i];
//                 profit = max(profit, sell - purchase_at);}        
//             }
​
//             if(profit > 0) return profit;
//             else return 0;
//         }
​
    }
};
