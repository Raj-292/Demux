// https://leetcode.com/problems/design-a-stack-with-increment-operation

class CustomStack {
public:
    vector<int> original_val_;
    vector<int> inc_val_;
    int size_;
    
    CustomStack(int maxSize) {
        size_ = maxSize;
    }
    
    // O(1)
    void push(int x) {
        if(original_val_.size() == size_)
            return;
        
        original_val_.push_back(x);
        inc_val_.push_back(0);
    }
    
    // O(1)
    int pop() {
        if(original_val_.empty())
            return -1;
        
        int last = original_val_.back() + inc_val_.back();
        
        // Transfer to the previous
        if(original_val_.size() > 1) {
            inc_val_[inc_val_.size()-2] += inc_val_.back();
        }
        
        // Remove
        original_val_.pop_back();
        inc_val_.pop_back();
        
        return last;
    }
    
    // O(1)
    void increment(int k, int val) {
        int n = original_val_.size();
        
        inc_val_[min(n, k)-1] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */