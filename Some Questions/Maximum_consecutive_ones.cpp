// you will be given an array with 0s and 1s and we may change up to K values from 0 to 1
// And we have to return there length of longest(contigious) subarray that contains only 1s
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    cout << "Enter the value of k" << endl;
    cin >> k;
    vector<int> a = {1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1};
    for (auto i : a)
        cout << i << " ";
    cout << endl;
    int n = a.size();
    int zeroCount = 0, i = 0, ans = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[j] == 0)
        {
            zeroCount++;
        }
        while (zeroCount > k)
        {
            if (a[i] == 0)
            {
                zeroCount--;
            }
            i++;
        }
        ans = max(ans, j - i + 1);
    }
    cout << ans;
    return 0;
}