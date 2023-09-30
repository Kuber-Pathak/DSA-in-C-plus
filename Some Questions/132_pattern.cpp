#include <bits/stdc++.h> // i<j<k
using namespace std;     // arr[i] < arr[k] < arr[j]

bool patternFinder(int arr[], int n)
{
    stack<int> s;
    int third = INT_MIN;

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] < third)
        {
            return true;
        }
        while (!s.empty() && arr[i] > s.top())
        {
            third = s.top();
            s.pop();
        }
        s.push(arr[i]);
    }
    return false;
}

int main()
{
    int arr[] = {1, 4, 3};
    if (patternFinder(arr, 4))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}