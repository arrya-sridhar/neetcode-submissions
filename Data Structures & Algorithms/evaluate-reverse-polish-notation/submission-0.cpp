class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> calc;
        for(string s : tokens){
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                int n1 = calc.top(); calc.pop();
                int n2 = calc.top(); calc.pop();
                if(s=="+") calc.push(n2+n1);
                if(s=="-") calc.push(n2-n1);
                if(s=="*") calc.push(n2*n1);
                if(s=="/") calc.push(n2/n1);
            }
            else calc.push(stoi(s));
        }
        return calc.top();
    }
};
