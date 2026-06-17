int init = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        int p1=0,p2=0,curr;
        for(int i=0;i<n;i++){
            curr = max(p1,nums[i]+p2);
            p2 = p1;
            p1 = curr;
        } 
        return curr;
    }
};
