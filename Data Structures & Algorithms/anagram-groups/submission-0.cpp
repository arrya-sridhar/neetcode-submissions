class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>> hash;
        for(int i=0;i<n;i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            hash[s].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for(auto& pair : hash) result.push_back(pair.second);
        return result;
    }
};
