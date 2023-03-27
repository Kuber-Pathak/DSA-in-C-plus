// In this problem we are given a array and a constant k ,and we have to dispaly the maximum in the window of k
// i.e we have to group the first k elements and find maximum among them, then group second k elements starting from second element and find their maximum and continue likewise.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cout << "Enter size of array,and value of k and array elements" << endl;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    multiset<int, greater<int>> s;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        s.insert(a[i]);
    }
    ans.push_back(*s.begin());
    // even i dont understood this part
    for (int i = k; i < n; i++)
    {
        s.erase(s.lower_bound(a[i - k]));
        s.insert(a[i]);
        ans.push_back(*s.begin());
    }
    for (auto i : ans)
        cout << i << " ";
    return 0;
}