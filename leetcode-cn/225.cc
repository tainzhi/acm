class MyStack
{
private:
    queue<int> ins;
    queue<int> outs;

public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        ins.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int result , length = ins.size();
        while (!ins.empty() && length > 1)
        {
            result = ins.front();
            outs.push(result);
            ins.pop();
            length--;
        }
        result = ins.front();
        ins.pop();
        while (!outs.empty() )
        {
            ins.push(outs.front());
            outs.pop();
        }
        return result;
    }

    /** Get the top element. */
    int top()
    {
        int result;
        while (!ins.empty())
        {
            result = ins.front();
            outs.push(result);
            ins.pop();
        }
        while (!outs.empty() )
        {
            ins.push(outs.front());
            outs.pop();
        }
        return result;

    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return ins.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */