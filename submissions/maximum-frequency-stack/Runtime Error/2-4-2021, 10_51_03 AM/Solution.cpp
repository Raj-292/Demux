// https://leetcode.com/problems/maximum-frequency-stack

class FreqStack {
public:
    int max_freq;
    unordered_map<int, int> counter;
    unordered_map<int, stack<int>> freq;
    FreqStack() {
        
    }
    
    void push(int x) {
        counter[x]++;
        int count=counter[x];
        freq[count].push(x);
        max_freq=max(max_freq,count);
    }
    
    int pop() {
        int x = freq[max_freq].top();
        freq[max_freq].pop();
        if(freq[max_freq].empty())
            max_freq--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */