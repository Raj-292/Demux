// https://leetcode.com/problems/maximal-rectangle

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        
        stack<int> st;
        int n = heights.size(), i, res = INT_MIN, tp, right, left, area, width;
        
        for(i = 0; i < n; i++) {
            // Keep popping >= numbers
            while(!st.empty() && heights[st.top()] > heights[i]) {
                // Calculate the histogram
                tp = st.top();
                st.pop();
                
                right = i;
                left = st.empty()? -1 : st.top();
                
                width = right-left-1;
                
                area = width*heights[tp];
                
                res = max(res, area);
            }
            
            st.push(i);
        }
        
        return res;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        
        int i, j, m = matrix.size(), n = matrix[0].size(), k, count = 0, res = INT_MIN;
        
        // Go row by row
        for(i = 0; i < m; i++) {
            // Construct the histogram with i as the base
            vector<int> heights(n);
            for(j = 0; j < n; j++) {
                count = 0;
                for(k = i; k >= 0 && matrix[k][j] == '1'; k--) {
                    count++;
                }
                
                heights[j] = count;
            }
            
            // Get the largest rectangle
            int lRectangle = largestRectangleArea(heights);
            
            res = max(res, lRectangle);
        }
        
        return res;
    }
};