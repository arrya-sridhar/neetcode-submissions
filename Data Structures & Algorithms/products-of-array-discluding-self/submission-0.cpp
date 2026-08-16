class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftm(n,1), rightm(n,1), answer(n,0);
        leftm[0] = nums[0];
        rightm[n-1] = nums[n-1];
        for(int i=1;i<n;i++) leftm[i] = leftm[i-1]*nums[i];
        for(int i=n-2;i>=0;i--) rightm[i] = rightm[i+1]*nums[i];
        for(int i=1;i<n-1;i++) answer[i] = leftm[i-1]*rightm[i+1];
        answer[0] = rightm[1];
        answer[n-1] = leftm[n-2];
        return answer; 
    }
};
