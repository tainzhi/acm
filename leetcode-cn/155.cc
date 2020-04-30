class MinStack {
private:
    stack<int> data;
    int min = INT_MAX;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (x <= min) {
            data.push(min);
            min = x;
        } 
        data.push(x);
    }
    
    void pop() {
        if (data.top() == min) {
            data.pop();
            min = data.top();
            data.pop();
        } else {
            data.pop();
        }
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */