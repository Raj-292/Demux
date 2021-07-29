// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    bool isOperator(string &op) {
        return op == "+" || op == "-" || op == "/" || op == "*";
    }
    
    int eval(int a, int b, string& op) {
        if(op == "+")
            return a+b;
        else if(op == "-")
            return a-b;
        else if(op == "*")
            return a*b;
        return a/b;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        for(int i = 0; i < tokens.size(); i++) {
            // Push a number into the stack
            if(!isOperator(tokens[i]))
                s.push(stoi(tokens[i]));
            else {
                // Evaluate the top two elements
                int t1 = s.top();
                s.pop();
                
                int t2 = s.top();
                s.pop();
                
                s.push(eval(t2, t1, tokens[i]));
            }
        }
        
        return s.top();
    }
};