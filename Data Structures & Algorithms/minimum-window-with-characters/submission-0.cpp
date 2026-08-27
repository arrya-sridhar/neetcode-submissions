class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        vector<int> actual(128,0), checkvec(128,0);
        for(char c : t) actual[c]++;
        int i=0, j=0, exists=0, startind=0, minc = m;
        checkvec[s[0]]++;
        while(j<m){
            int check = 0;
            for(int k=0;k<128;k++) if(actual[k]>checkvec[k]) check = 1;
            if(check==1){
                j++;
                checkvec[s[j]]++;
            }
            else{
                if(j-i+1 < minc){
                    minc = j-i+1;
                    startind = i;
                }
                exists = 1;
                checkvec[s[i]]--;
                i++;
            }
        }
        if(exists==1) return s.substr(startind,minc);
        return "";
    }
};
