class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,0);
        dp[0] = 1;
        if(s[0]-48 == 0) return 0;
        for(int i=1;i<n;i++){
            if(s[i]-48 == 0 && (s[i-1]-48>2 || s[i-1]-48<1)) return 0;
            else if(s[i]-48 == 0 && s[i-1]-48<=2 && s[i-1]-48>=1){
                if(i>1) dp[i] = dp[i-2];
                else dp[i] = dp[i-1];
            }
            else if((s[i]-48)<7 && (s[i]-48)>0 && s[i-1]-48==2 && i>1) dp[i] = dp[i-1] + dp[i-2]; 
            else if((s[i]-48)<7 && (s[i]-48)>0 && s[i-1]-48==2) dp[i] = dp[i-1] + 1;
            else if((s[i]-48)<10 && (s[i]-48)>0 && s[i-1]-48==1 && i>1) dp[i] = dp[i-1] + dp[i-2]; 
            else if((s[i]-48)<10 && (s[i]-48)>0 && s[i-1]-48==1) dp[i] = dp[i-1] + 1;   
            else dp[i] = dp[i-1];    
        }
        return dp[n-1];
    }
};
