class MyQueue {
private:
    stack<int>  in;
    stack<int> out;
    int front;
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp;
        while (!in.empty()) {
            tmp = in.top();
            in.pop();
            out.push(tmp);
        }
        int result = out.top();
        out.pop();
        while (!out.empty()) {
            tmp = out.top();
            out.pop();
            in.push(tmp);
        }
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        int tmp;
        while (!in.empty()) {
            tmp = in.top();
            in.pop();
            out.push(tmp);
        }
        int result = out.top();
        while (!out.empty()) {
            tmp = out.top();
            out.pop();
            in.push(tmp);
        }
        return result;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return in.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */