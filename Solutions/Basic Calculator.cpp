class Solution {
public:
    int calculate(string s1) {

        string s = "(" + s1 + ")";

        int n = s.size(), i;
        string num = "";
        stack<string> st;


        for (i = 0; i < n; i++) {
            if (s[i] == ' ')
                continue;

            if (isdigit(s[i])) {
                // String concatenation
                num += s[i];
                continue;
            }

            if (num != "") {
                if (!st.empty() && (st.top() == "+" || st.top() == "-")) {
                    string t = st.top();
                    st.pop();
                    num = t + num;
                }
                st.push(num);
                num = "";
            }

            if (s[i] == '+' || s[i] == '-' || s[i] == '(') {
                string temp = "";
                temp = temp + s[i];
                st.push(temp);
                continue;
            }

            // You have a ')'
            // Pop and evaluate
            int exp = 0;
            while (st.top() != "(") {
                string k = st.top();
                st.pop();

                exp += stoi(k);
            }

            st.pop();

            string exp_str = to_string(exp);

            // Prepend sign if needed
            if (!st.empty() && (st.top() == "+" || st.top() == "-")) {
                if (exp < 0 && st.top() == "-") {
                    exp_str[0] = '+';
                }
                else if (exp >= 0) {
                    string t = st.top();
                    exp_str = t + exp_str;
                }

                st.pop();
            }

            st.push(exp_str);
        }

        return stoi(st.top());
    }
};