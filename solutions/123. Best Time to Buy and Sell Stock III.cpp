        for(int i=1;i<size;i++){
            if(prices[i]<purchase_at) purchase_at=prices[i];
            dp[i] = max(dp[i-1],dp[i]+(prices[i]-purchase_at));
        }
        
        return dp[size-1];
        
        
        //Simple Aproach
        
//         int buy1, profit1, buy2, profit2;
//         int n = price.size();
​
//         buy1 = buy2 = INT_MAX;
//         profit1 = profit2 = 0;
​
//         for (int i = 0; i < n; i++) {
//             buy1 = min(buy1, price[i]);
//             profit1 = max(profit1, price[i] - buy1);
//             buy2 = min(buy2, price[i] - profit1);      //profit made by 1st stock
//             profit2 = max(profit2, price[i] - buy2);
//         }
 
//         return profit2;
        
        
        
    }
};
