// https://leetcode.com/problems/design-a-stack-with-increment-operation

class CustomStack {
public:
    vector<int> custom_stack_;
    int size_;
    
    CustomStack(int maxSize) {
        size_ = maxSize;
    }
    
    // O(1)
    void push(int x) {
        if(custom_stack_.size() == size_)
            return;
        
        custom_stack_.push_back(x);
    }
    
    // O(1)
    int pop() {
        if(custom_stack_.empty())
            return -1;
        
        int last = custom_stack_.back();
        custom_stack_.pop_back();
        
        return last;
    }
    
    // O(k)
    void increment(int k, int val) {
        int n = custom_stack_.size();
        
        for(int i = 0; i < min(k, n); i++)
            custom_stack_[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */