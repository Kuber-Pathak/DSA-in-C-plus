// n-array of number of pages in n different books [ascending order]
// m-number of students
//  all the books have to be divided among m students, consecutively.
//  Allocate the pages in such a way that maximum pahes allocated to a student is minimum.
#include <iostream>
#include <climits>
using namespace std;

bool isFeasible(int min, int arr[], int n, int m)
{
    int students = 1, sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > min)
        {
            return false;
        }
        if (sum + arr[i] > min)
        {
            students++;
            sum = arr[i];

            if (students > m)
            {
                return false;
            }
        }
        else
        {
            sum += arr[i];
        }
    }
    return true;
}

int minimumPage(int arr[], int n, int m)
{
    if (n < m)
    {
        return -1;
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    int start = 0, end = sum, result = INT_MAX;
    while (start <= end)
    {
        int mid = (end + start) / 2;
        if (isFeasible(mid, arr, n, m))
        {
            result = min(result, mid);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return result;
}

int main()
{
    int arr[] = {12, 34, 67, 90};
    cout << "The minimum no of pages : " << minimumPage(arr, 4, 2) << endl;
    return 0;
}