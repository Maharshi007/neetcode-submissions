class Solution {
    int op(int a, int b, char ch) {
        switch (ch) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
        }
        return 0;
    }

   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int res;
        for (auto& it : tokens) {
            if (it == "+" || it == "-" || it == "*" || it == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(op(a, b, it[0]));
            } else {
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};
