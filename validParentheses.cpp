bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> st;
    for(char ch : expression)
    {
        if(ch == '(' || ch == '{' || ch == '[')
            st.push(ch);
        else {
            if (st.empty())
                return false;
            else if (ch == ')' && st.top() != '(')
                return false;
            else if (ch == '}' && st.top() != '{')
                return false;
            else if (ch == ']' && st.top() != '[')
                return false;
            else
                st.pop();
        }
    }
    return st.empty();
}