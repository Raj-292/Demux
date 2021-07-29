// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    bool isOperator(string& op)
    {
        return op=="+" || op=="-"||op=="/"|| op=="*";
    }
    
    int eval(int a, int b, string& s)
    {
        if(s=="+")
            return a+b;
        else if(s=="-")
            return a-b;
        else if(s=="/")
            return a/b;
        return a*b;
        
    }
    
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        
        for(int i=0;i<tokens.size();i++)
        {
            if(isOperator(tokens[i])==false)
                st.push(stoi(tokens[i]));
          else
            {
                int t2=st.top();
                st.pop();
                int t1=st.top();
                st.pop();
                
                int num = eval(t1,t2,tokens[i]);
                
                st.push(num);
                
                
            }
            
            
        }
        
        return st.top();
    }
};