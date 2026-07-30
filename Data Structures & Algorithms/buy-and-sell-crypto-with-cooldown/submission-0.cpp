class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxp = 0;
        vector<vector<int>> dp(3 , vector<int> (n,0));
        // [0] : rest , [1] : hold , [2] : sold
        dp[0][0] = 0;
        dp[1][0] = -prices[0];
        dp[2][0] = 0;
        for(int i=1;i<n;i++){
            dp[0][i] = max(dp[0][i-1],dp[2][i-1]);
            dp[1][i] = max(dp[1][i-1],dp[0][i-1]-prices[i]);
            dp[2][i] = dp[1][i-1]+prices[i];
            if(dp[0][i]>maxp) maxp = dp[0][i];
            if(dp[2][i]>maxp) maxp = dp[2][i];
        }
        return maxp;

    }
};
