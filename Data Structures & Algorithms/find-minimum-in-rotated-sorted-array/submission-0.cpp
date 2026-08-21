class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size(),l=0,r=n-1;
        if(nums[l]<nums[r]) return nums[l];
        while(l<=r){
            int m = (l+r)/2;
            if(nums[l]>nums[m]) r = m;
            else if(nums[l]<=nums[m]&&nums[m]>nums[r]) l = m+1;
            else r = m-1;
        }
        return nums[l];
    }
};
