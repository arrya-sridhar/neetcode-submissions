class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for( string s : strs){
            int len = s.size();
            encoded_string += to_string(len)  + "#" + s;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strs;
        int n = s.size(),i=0;
        string str,count;
        while(i<n){
            if(s[i]=='#'){
                int c = stoi(count);
                for(int j=i+1;j<=i+c;j++) str += s[j];
                decoded_strs.push_back(str);
                i += c+1;
                str = "";
                count = "";
            }
            count += s[i];
            i++;
        }
        return decoded_strs;
    }
};
