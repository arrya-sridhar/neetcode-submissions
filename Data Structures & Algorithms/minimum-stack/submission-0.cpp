class MinStack {
private:
    stack<int> st,min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(min.size()==0) min.push(val);
        else if(val<min.top()) min.push(val);
        else min.push(min.top());
    }
    
    void pop() {
        min.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
};
