class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        vector<int> dp1(n-1,0), dp2(n-1,0), dp3(n-2,0);
        for(int i=0;i<n-1;i++){
            if(i==0){
                dp1[i] = nums[i];
                continue;
            }
            if(i==1){
                dp1[i] = max(dp1[i-1],nums[i]);
                continue;
            }
            dp1[i] = max(dp1[i-1],nums[i]+dp1[i-2]);
        } 
        for(int i=1;i<n;i++){
            if(i==1){
                dp2[i-1] = nums[i];
                continue;
            }
            if(i==2){
                dp2[i-1] = max(dp2[i-2],nums[i]);
                continue;
            }
            dp2[i-1] = max(dp2[i-2],nums[i]+dp2[i-3]);
        }
        for(int i=1;i<n-1;i++){
            if(i==1){
                dp3[i-1] = nums[i];
                continue;
            }
            if(i==2){
                dp3[i-1] = max(dp3[i-2],nums[i]);
                continue;
            }
            dp3[i-1] = max(dp3[i-2],nums[i]+dp3[i-3]);
        }
        return max(dp1[n-2],max(dp2[n-2],dp3[n-3]));
    }
};
