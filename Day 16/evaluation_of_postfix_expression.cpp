int evaluatePostfix(string S) {
    stack<int> st;
    
    for (char ch : S) {
        if (isdigit(ch)) {
            // Push the operand (as an integer) onto the stack
            st.push(ch - '0');
        } 
        else {
            // Pop the top two elements for the operator
            int op2 = st.top(); st.pop();
            int op1 = st.top(); st.pop();
            
            // Perform the operation and push the result back
            switch (ch) {
                case '+': st.push(op1 + op2); break;
                case '-': st.push(op1 - op2); break;
                case '*': st.push(op1 * op2); break;
                case '/': st.push(op1 / op2); break;
            }
        }
    }
    
    // The final result will be the only element left in the stack
    return st.top();
}
