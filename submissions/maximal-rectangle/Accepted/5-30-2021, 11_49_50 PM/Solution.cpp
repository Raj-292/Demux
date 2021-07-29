// https://leetcode.com/problems/maximal-rectangle

class Solution {
public:
      int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        
        int n = heights.size(),area,width,l,r,res;
        stack<int> st;
        
        for(int i=0;i<n;i++)
        {
            //keep poping when top >= curr_num
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                int tp=st.top();
                st.pop();
                
                width=i-1-(st.empty()?-1:st.top());
                
                area=width*heights[tp];
                res=max(res,area);
            }
            
            st.push(i);
            
        }
        cout<<res;
        st.empty();  
        return res;
      }
            
        
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        int m=matrix.size(),n=matrix[0].size(),res=0;
        
        for(int i=0;i<m;i++)
        {
            vector<int> height(n);
            
            
            for(int j=0;j<n;j++)
            { 
                int c=0;
                for(int k=i;k>=0 && matrix[k][j]=='1';k--)
                {
                    c++;
                }
                
                height[j]=c;
            }
            
            int area = largestRectangleArea(height);
          //  cout<<area<<endl;
            res=max(res,area);
        }
        return res;
        
        
    }
};