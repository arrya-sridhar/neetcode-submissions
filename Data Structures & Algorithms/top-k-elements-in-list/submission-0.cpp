class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int> hash;
       vector<int> res;
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
       for(int n : nums) hash[n]++;
       for(auto& pair : hash){
            q.push({pair.second,pair.first});
            if(q.size()>k) q.pop();
        }
        while(q.size()>0){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
