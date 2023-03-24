#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;
bool isValid(string s)
{
    int n = s.size();
    stack<char> st;
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        if ((s[i] == '{') || (s[i] == '(') || (s[i] == '['))
        {
            st.push(s[i]);
        }
        else if (!st.empty() && s[i] == ')')
        {
            if (st.top() == '(')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (!st.empty() && s[i] == '}')
        {
            if (st.top() == '{')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (!st.empty() && s[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    if (!st.empty())
    {
        return false;
    }
    return true;
}
int main()
{
    string s = "[{([])}]";
    if (isValid(s))
    {
        cout << "Valid String" << endl;
    }
    else
    {
        cout << "Invalid string" << endl;
    }
    return 0;
}