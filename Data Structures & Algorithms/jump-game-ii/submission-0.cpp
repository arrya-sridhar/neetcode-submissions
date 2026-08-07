class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(),reach=nums[0],jumps=1,i=1,maxreach=nums[0];
        if(n==1) return 0;
        while(i<n){
            if(i<=reach) maxreach = max(i+nums[i],maxreach);
            else{
                jumps++;
                reach = maxreach;
                maxreach = max(i+nums[i],maxreach);
            }
            i++;
        }
        return jumps;
    }
};
