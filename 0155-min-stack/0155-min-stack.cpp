class MinStack {
public:
    vector<int> stack;
    vector<int> minStack;
    
    MinStack() { }
    
    void push(int val) {
        stack.push_back(val);
        if (minStack.empty() || val <= minStack.back()) {
            minStack.push_back(val);
        }
    }
    
    void pop() {
        if (stack.empty()) return;
        if (stack.back() == minStack.back()) {
            minStack.pop_back();
        }
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minStack.back();
    }
};
