// You will be given a mathematical expression and we have to find if it has any extra or unnecessary brackets
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "((a+b))";
    stack<char> st;
    int r = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            st.push(s[i]);
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.top() == '(')
            {
                r++;
            }
            while (st.top() == '+' or st.top() == '-' or st.top() == '*' or st.top() == '/')
            {
                st.pop();
            }
            st.pop();
        }
    }
    cout << "No. of redundant parenthesis = " << r << endl;
    return 0;
}