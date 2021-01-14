class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int dp[size];
        for(int i=0;i<size;i++) dp[i]=0;
        
        int sell_at = prices[size-1]; //Maximum
        int purchase_at = prices[0];  //Minimum
        
        //Go from last to 1st element and add max profit in dp
        for(int i=size-2;i>=0;i--){
            if(prices[i]>sell_at) sell_at=prices[i];
            dp[i] = max(dp[i+1], sell_at-prices[i]);
        }
        
        //Go from 1st to last element and add max profit in previous dp
        for(int i=1;i<size;i++){
            if(prices[i]<purchase_at) purchase_at=prices[i];
            dp[i] = max(dp[i-1],dp[i]+(prices[i]-purchase_at));
        }
        
        return dp[size-1];
        
    }
};
