// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<double,vector<double>,greater<>> minq;
    priority_queue<double> maxq;
    // last iteration
    bool odd = true;
    
    MedianFinder() {
        // 
    }
    
    void addNum(int num) {
        if(odd){
            minq.push(num);
            maxq.push(minq.top());
            minq.pop();
        } else{
            maxq.push(num);
            minq.push(maxq.top());
            maxq.pop();
        }
        odd=!odd;
    }
    
    double findMedian() {
        if(odd){
            return ((maxq.top()+minq.top())/2);
        } else return maxq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */