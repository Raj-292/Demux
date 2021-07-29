// https://leetcode.com/problems/maximum-frequency-stack

class FreqStack {
public:
    int max_freq;
    unordered_map<int, int> counter;
    vector<stack<int>> rev_freq;
    
    FreqStack() {
         rev_freq.resize(10005);   
    }
    
    void push(int x) {
        // Increase the counter
        counter[x]++;
        
        // Get the counter and push it in the stack
        int count = counter[x];
        
        rev_freq[count].push(x);
        
        // Update the max_freq
        max_freq = max(max_freq, count);
    }
    
    int pop() {
        // Remove the most frequent
        int last = rev_freq[max_freq].top();
        
        rev_freq[max_freq].pop();
        
        // Update the count
        counter[last]--;
        
        // Update the max_freq
        if(rev_freq[max_freq].empty())
            max_freq--;
        
        return last;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */