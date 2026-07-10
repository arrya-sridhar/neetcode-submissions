class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> check(128,0);
        int i=0,j=0,max=0;
        while(i>=0 && j<n){
            if(check[s[j]]<1){
                check[s[j]]++;
                j++;
                if(j-i > max) max = j - i;
            }
            else{
                while(check[s[j]]>0){
                    check[s[i]]--;
                    i++;
                }
                check[s[j]]++; 
                j++;
                if(j-i > max) max = j - i;
            }
        }
        return max;
    }
};

