class Solution {
public:
    int op(int a, int b, string vo) {
        if(vo == "+") return a + b;
        else if(vo == "-") return a - b;
        else if(vo == "*") return a * b;
        else return a / b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0; i<tokens.size(); i++) {
            if(!(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")) 
            st.push(stoi(tokens[i]));
            else {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int c = op(a, b, tokens[i]);
                st.push(c);
            }
        }

        return st.top();
    }
};
