// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), i, width, area, res = INT_MIN;
        vector<int> next_smaller(n);
        
        // Store index in the stack
        stack<int> st;
        
        for(i = n-1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            
            if(st.empty())
                next_smaller[i] = n;
            else
                next_smaller[i] = st.top();
            
            st.push(i);
        }
        
        stack<int> st1;
        
        for(i = 0; i < n; i++) {
            while(!st1.empty() && heights[st1.top()] >= heights[i])
                st1.pop();
            
            if(st1.empty()) {
                width = next_smaller[i];
            }
            else {
                width = next_smaller[i] - st1.top() - 1;
            }
            
            area = heights[i]*width;
            
            res = max(res, area);
            
            st1.push(i);
            
        }
        
        return res;
    }
};