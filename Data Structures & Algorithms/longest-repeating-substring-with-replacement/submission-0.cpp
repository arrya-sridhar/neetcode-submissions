class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0, j=0, maxc=0, maxf=0;
        vector<int> count(26,0);
        while(j<s.size()){
            count[s[j]-'A']++;
            for(int i=0;i<26;i++) maxf = max(maxf,count[i]);
            if(maxf + k < j-i+1){
                count[s[i]-'A']--;
                i++;
            }
            maxc = max(maxc,j-i+1);
            j++;
        }
        return maxc;
    }
};
