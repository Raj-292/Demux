// https://leetcode.com/problems/design-front-middle-back-queue

class FrontMiddleBackQueue {
public:
    void show(vector<int> &v){
        for(auto a: v)
            cout<<a<<" ";
        cout<<endl;
    }
    vector<int> v{};
    int i,front, last, size, t ,n;
    void pop_front(vector<int> &v)
{
    if (v.size() > 0) {
        v.erase(v.begin());
    }
        if(v.size())
            show(v);
}
    FrontMiddleBackQueue() {
        
        front=last=-1;
        size=0;
    }
    
    void pushFront(int val) {
        v.push_back(0);
        for(i=0; i<(v.size()-1); i++)
            v[i+1] = v[i];
        v[0]=val;
        if(v.size())
            show(v);
    }
    
    void pushMiddle(int val) {
        n=v.size();
        v.push_back(0);
        if(v.size())
            show(v);
        if(n%2==1)
        {
            for(i= v.size()-1; i-1 >= n/2; i--)
                v[i]=v[i-1];
            v[n/2]=val;
        }
        else{
            for(i= v.size()-1; i-1 >= n/2; i--)
                v[i]=v[i-1];
            v[n/2]=val;
           
        }
        if(v.size())
            show(v);
    }
    
    void pushBack(int val) {
        
        v.push_back(val);
        if(v.size())
            show(v);
    }
    
    int popFront() {
        if(v.size()==0)
            return -1;
        t=v[0];
        pop_front(v);
        if(v.size())
            show(v);
        return t;
    }
    
    int popMiddle() {
        n=v.size();
        if(n%2==0)
        {
            t=v[n/2-1];
            for(i= n/2-1; i<(v.size()-1); i++)
                v[i]=v[i+1];
            v.pop_back();
            if(v.size())
            show(v);
            return t;
        }
        else{
            t=v[n/2];
            for(i= n/2; i<(v.size()-1); i++)
                v[i]=v[i+1];
            v.pop_back();
            if(v.size())
            show(v);
            return t;
        }
    }
    
    int popBack() {
        if(v.size()==0)
            return -1;
        t=v.back();
        v.pop_back();
        if(v.size())
            show(v);
        return t;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */