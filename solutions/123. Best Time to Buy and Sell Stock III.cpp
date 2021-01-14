class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int dp[size];
        for(int i=0;i<size;i++) dp[i]=0;
        
        int selling = prices[size-1];
        int purchasing = prices[0];
        
        //Go from last to 1st element and add max profit in dp
        for(int i=size-2;i>=0;i--){
            if(prices[i]>selling) selling=prices[i];
            dp[i] = max(dp[i+1], selling-prices[i]);
        }
        
        //Go from 1st to last element and add max profit in previous dp
        for(int i=1;i<size;i++){
            if(prices[i]<purchasing) purchasing=prices[i];
            dp[i] = max(dp[i-1],dp[i]+(prices[i]-purchasing));
        }
        
        return dp[size-1];
        
    }
};
