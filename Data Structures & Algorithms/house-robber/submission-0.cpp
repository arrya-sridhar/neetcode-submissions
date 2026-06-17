class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        for(int i=0;i<n;i++){
            if(i==0){
                dp[i] = nums[i];
                continue;
            }
            if(i==1){
                dp[i] = max(dp[i-1],nums[i]);
                continue;
            }
            dp[i] = max(dp[i-1],nums[i]+dp[i-2]);
        } 
        return dp[n-1];
    }
};
