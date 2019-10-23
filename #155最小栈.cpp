class MinStack {
public:
    stack<int> s;//数据栈
    stack<int> min;//辅助栈
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(min.empty()||x<=min.top())
        {
            min.push(x);
        }
    }
    
    void pop() {
        if(s.top()==min.top())
            min.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    int getMin() {
        return min.top();
    }
};
