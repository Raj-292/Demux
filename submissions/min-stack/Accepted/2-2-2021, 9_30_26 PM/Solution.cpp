// https://leetcode.com/problems/min-stack

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s1;
        stack<int> s2;
        
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty())
        {
             s2.push(x);
        }
        else
            s2.push(min(x,s2.top()));
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        int x=s1.top();
        return x;
        
    }
    
    int getMin() {
           int x=s2.top();
        return x;
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