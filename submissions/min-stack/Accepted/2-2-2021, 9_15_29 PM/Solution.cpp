// https://leetcode.com/problems/min-stack

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s1; // Empty stack of integers
    stack<int> s2; // Empty stack of integers
    // s1.push(x), s1.pop(), s1.top(), s1.empty()
    MinStack() {
    }
    
    void push(int x) {
        // Push into s1
        s1.push(x);
        // Push into s2
        // push the min of top and x
        if(s2.empty())
            s2.push(x);
        else
            s2.push(min(x, s2.top()));
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
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