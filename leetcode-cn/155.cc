/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
private:
    stack<int> s;
    int min = INT_MAX;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if (x <= min) {
            s.push(min);
            min = x;
        }
        s.push(x);
    }
    
    void pop() {
        int top = s.top();
        s.pop();
        if (top == min) {
            min = s.top();
            s.pop();
        }
    }
    
    int top() {
        return s.top();
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
// @lc code=end

