// Given is an array with n elements that represents n positions along a straight line .
// Find K elements such that the minimum distance between any 2 elements is the maximum possible.

#include <iostream>
#include <algorithm>
using namespace std;

bool isFeasible(int mid, int arr[], int n, int k)
{
    int position = arr[0], elements = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - position >= mid)
        {
            position = arr[i];
            elements++;
            if (elements == k)
            {
                return true;
            }
        }
    }
    return false;
}

int largestDistance(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int result = -1;
    int start = 1, end = arr[n - 1];
    while (start < end)
    {
        int mid = (end + start) / 2;
        if (isFeasible(mid, arr, n, k))
        {
            result = max(result, mid);
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return result;
}

int main()
{
    int arr[6] = {11, 2, 7, 5, 1, 12};
    cout << "The largest distance is : " << largestDistance(arr, 6, 3) << endl;
    return 0;
}