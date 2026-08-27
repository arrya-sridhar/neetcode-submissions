class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n-k+1,0);
        priority_queue<pair<int,int>> maxheap;
        for(int i=0;i<k;i++) maxheap.push({nums[i],i});
        result[0] = maxheap.top().first;
        for(int i=0;i<n-k;i++){
            maxheap.push({nums[i+k],i+k});
            int given = 0;
            while(given==0){
                if(maxheap.top().second>i){
                    result[i+1] = maxheap.top().first;
                    given = 1;
                }
                else maxheap.pop();
            }
        }
        return result;
    }
};
