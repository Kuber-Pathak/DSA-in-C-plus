// The span of the stocks price today is defined as the maximum number of consecutive days(starting from today and going backwards) for which
// the price of the stoks was less than or equal to today sprice.Find the span of the stocks for all the days
#include <bits/stdc++.h>
using namespace std;
vector<int> stockSpan(vector<int> prices)
{
    vector<int> ans;
    stack<pair<int, int>> s;
    for (auto price : prices)
    {
        int days = 1;
        while (!s.empty() and s.top().first <= price)
        {
            days += s.top().second;
            s.pop();
        }
        s.push({price, days});
        ans.push_back(days);
    }
    return ans;
}
int main()
{
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> res = stockSpan(prices);
    for (auto i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}