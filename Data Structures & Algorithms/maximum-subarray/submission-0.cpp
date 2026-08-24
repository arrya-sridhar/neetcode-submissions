class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int count=0, maxc=INT_MIN;
        for(int n : nums){
            count += n;
            if(count>maxc) maxc = count;
            if(count<1) count = 0;
        }
        return maxc;
    }
};
