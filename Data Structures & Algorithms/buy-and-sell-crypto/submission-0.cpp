class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), max = 0, result = 0;
        vector<int> rmax(n,0);
        for(int i=n-1;i>=0;i--){
            if(prices[i]>max) max = prices[i];
            if(max>prices[i]) rmax[i] = max - prices[i];
        }
        for(int i=0;i<n;i++) if(rmax[i]>result) result = rmax[i];
        return result;
    }
};
