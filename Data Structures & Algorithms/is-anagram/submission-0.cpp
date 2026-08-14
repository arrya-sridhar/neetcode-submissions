class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if(m!=n) return false;
        unordered_map<char,int> hash1,hash2;
        for(int i=0;i<n;i++){
            hash1[s[i]]++;
            hash2[t[i]]++;
        }    
        for(int i=0;i<n;i++) if(hash1[s[i]]!=hash2[s[i]]) return false;
        return true;
    }
};
