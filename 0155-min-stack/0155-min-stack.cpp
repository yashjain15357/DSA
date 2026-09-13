class MinStack {
public:
    std::stack<int> st;
    std::stack<int> minstack;

    MinStack() {}
    
    void push(int val) {
        st.push(val);
        // Push to minstack if it's empty or val is <= current minimum
        if (minstack.empty() || val <= minstack.top()) {
            minstack.push(val);
        }
    }
    
    void pop() {
        // If the element being removed is the current minimum, pop from minstack too
        if (st.top() == minstack.top()) {
            minstack.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */