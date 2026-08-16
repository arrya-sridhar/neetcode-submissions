class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hash;
        int maxc = 0;
        for(int i=0;i<nums.size();i++) hash[nums[i]]++;
        for(auto& pair : hash){
            if(hash.count(pair.first-1)<1){
                int count = 1, i = pair.first;
                while(hash.count(i+1)>0){
                    count++;
                    i++;
                }
                if(count > maxc) maxc = count;
            }
        }
        return maxc;
    }
};
