class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int t = amount;
        sort(coins.begin(), coins.end());
        vector<int> dp(t+1, t+1);
        dp[0] = 0;
        for(int i=0;i<n;i++){
            if(coins[i]<=t) dp[coins[i]] = 1;
        } 
        for(int i=1;i<t+1;i++){
            int min = 1e8;
            int num = 0 ;
            for(int j=0;j<n;j++){
                if(coins[j]<=i) num++;
            }
            for(int j=0;j<num;j++){
                if(dp[i-coins[j]]<min) min = dp[i-coins[j]];
            }
            dp[i] = 1 + min;
        }
        if(dp[t]>t) return -1;
        else return dp[t];
    }
};
