class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            if(c=='(' || c=='[' || c=='{') st.push(c);
            else if(st.size()>0 && (st.top()=='(' && c==')' || st.top()=='[' && c==']' || st.top()=='{' && c=='}')) st.pop();
            else st.push(c);
        }
        if(st.size()>0) return false;
        else return true;
    }
};
