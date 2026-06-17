class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        int p1=0,pp1=0,p2=0,pp2=0,curr1,curr2;
        for(int i=0;i<n-1;i++){
            curr1=max(p1,nums[i]+pp1);
            pp1=p1;
            p1=curr1;
        } 
        for(int i=1;i<n;i++){
            curr2=max(p2,nums[i]+pp2);
            pp2=p2;
            p2=curr2;
        }
    
        return max(curr1,curr2);
    }
};
