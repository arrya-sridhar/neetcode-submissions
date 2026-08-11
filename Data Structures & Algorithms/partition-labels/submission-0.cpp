class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size(),maxindex=0,startindex=0;
        vector<int> ans;
        vector<int> last(26,0);
        for(int i=0;i<n;i++) last[s[i]-'a'] = i;
        for(int i=0;i<n;i++){
            if(last[s[i]-'a']>maxindex) maxindex = last[s[i]-'a'];
            if(i==maxindex){
                ans.push_back(i-startindex+1);
                startindex = i+1;
            }
        }
        return ans;
    }
};
