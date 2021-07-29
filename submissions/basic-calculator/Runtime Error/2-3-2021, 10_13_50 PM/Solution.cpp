// https://leetcode.com/problems/basic-calculator

class Solution {
public:
    int calculate(string s1) {
        
        string s = "("+s1+")";
        // string s = (s1[0] != '(')? "("+s1+")": s1;
        
        // cout << s << endl;
        
        int n = s.size(), i;
        string num = "";
        stack<string> st;
        
        
        for(i = 0; i < n; i++) {
            if(s[i] == ' ')
                continue;
            
            if(isdigit(s[i])) {
                // String concatenation
                num += s[i];
                continue;
            }
            
            if(num != ""){
                if(!st.empty() && (st.top() == "+" || st.top() == "-")) {
                    string t = st.top();
                    st.pop();
                    num = t + num;
                }
                st.push(num);
                num = "";
            }
            
            if(s[i] == '+' || s[i] == '-' || s[i] == '(') {
                string temp = "";
                temp = temp + s[i];
                st.push(temp);
                continue;
            }
            
//             cout << s[i] << endl;
            
            // cout << st.size() << endl;
            // stack<string> st1 = st;
            // while(!st1.empty()) {
            //     cout << st1.top() << ", ";
            //     st1.pop();
            // }
            // cout << endl;
            // You have a ')'
            // Pop and evaluate
            int exp = 0;
            while(st.top() != "(") {
                string k = st.top();
                st.pop();
                
                exp += stoi(k);
            }
            
            st.pop();
            
            string exp_str = to_string(exp);
            
            // Prepend sign if needed
            if(!st.empty() && (st.top() == "+" || st.top() == "-")) {
                string t = st.top();
                st.pop();
                exp_str = t + exp_str;
            }
            
            st.push(exp_str);
        }
        
        return stoi(st.top());
    }
};