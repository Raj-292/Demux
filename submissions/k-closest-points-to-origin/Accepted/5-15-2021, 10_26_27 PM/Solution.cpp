// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    typedef vector<int> point;
    
    struct compare{
      bool operator()(point a, point b){
          return a[0]*a[0]+a[1]*a[1] > b[0]*b[0]+b[1]*b[1];
      }  
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // sort(start,end,compare);
        priority_queue<point,vector<point>,compare> minq(points.begin(),points.end());
        vector<point> res;
        while(k--){
            res.push_back(minq.top());
            minq.pop();
        }
        return res;
    }
};