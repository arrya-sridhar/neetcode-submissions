class Solution {
public:
    bool isPalindrome(string s) {
        string result = "";
        for(char c:s) if(isalnum(c)) result += tolower(c);
        int n = result.size();
        int i=0,j=n-1;
        while(i<=j){
            if(result[i]!=result[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
