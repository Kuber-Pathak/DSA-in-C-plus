// given a non negative integer representing a elevation map where the width of each bar is 1,
// compute how much water it can teap after raining
#include <bits/stdc++.h>
using namespace std;
int rain_water(vector<int> a)
{
    stack<int> st;
    int ans = 0, n = a.size();
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] < a[i])
        {
            int cur = st.top();
            st.pop();
            if (st.empty())
            {
                break;
            }
            int l = i - st.top() - 1;
            int w = (min(a[st.top()], a[i]) - a[cur]);
            ans += w * l;
        }
        st.push(i);
    }
    return ans;
}
int main()
{
    vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << rain_water(a);
    return 0;
}