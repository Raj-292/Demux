// https://leetcode.com/problems/my-calendar-i

class MyCalendar {
public:
    map <int, int> m;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = m.lower_bound(start);
        
        
        // Check if this interval overlaps with the lower bound
        // ie: is the end of this interval greater than the start of the lower bound
        if(it != m.end() && end > it -> first) return false;
        
        
        // Check the previous of the lower bound
        // Check if this one overlaps
        if(it != m.end()) {
            it --;
            if(it -> second > start) return false
        }
        
        // Valid interval
        m[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */