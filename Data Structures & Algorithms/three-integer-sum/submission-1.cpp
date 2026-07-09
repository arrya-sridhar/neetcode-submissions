class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i=0;i<n-2;i++){
            int target = nums[i]*(-1), j = i+1, k = n-1;
            while(j<k){
                int sum = nums[j]+nums[k];
                if(sum==target){
                    result.push_back({nums[i],nums[j],nums[k]}); 
                    while(i<n-2 && nums[i]==nums[i+1]) i++;
                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(j<k && nums[k]==nums[k-1]) k--;
                }       
                if(sum<target) j++;
                else k--;
            }
        }
        return result;
    }
};
