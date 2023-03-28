// In the given array u have to find 3 numbers whose sum is equal to the sum you are given to fin
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int target;
    cout << "Enter the required sum" << endl;
    cin >> target;
    vector<int> a = {12, 3, 6, 9, 34, 25};
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;
    bool found = false;
    int n = a.size();
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        int lo = i + 1, hi = n - 1;
        while (lo < hi)
        {
            int current = a[i] + a[lo] + a[hi];
            if (current == target)
            {
                found = true;
                cout << "The numbers are " << a[i] << "+" << a[lo] << "+" << a[hi] << " = " << target << endl;
            }
            if (current < target)
            {
                lo++;
            }
            else
            {
                hi--;
            }
        }
    }
    if (!found)
    {
        cout << "The sum doesnt exist." << endl;
    }
    return 0;
}