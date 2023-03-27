// In this problem we are given a array and a constant k ,and we have to dispaly the maximum in the window of k
// i.e we have to group the first k elements and find maximum among them, then group second k elements starting from second element and find their maximum and continue likewise.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {-10, 2, 9, 10, 3, 4, 0, 3};
    deque<int> q; // Remember : We will be adding the indices to the deque not the elements.
    int k = 3;
    vector<int> MaximumOfEachWindow;

    // for first k elements
    for (int i = 0; i < k; i++)
    {
        while (!q.empty() && arr[i] >= arr[q.back() /*remember we are dealing with indices in q*/])
        {

            /*so the above line means, if the current element is greater than
            the last index pushed to the deque*/

            q.pop_back();
            /*remove every element from the deque*/
        }

        /* add the index of the newly discovered maximum element*/

        q.push_back(i);
    }

    // push this to our answer but remember dont do q.front() as we are dealing with indices.

    MaximumOfEachWindow.push_back(arr[q.front()]);

    // for k -> n

    for (int i = k; i < arr.size(); i++)
    {
        /*first we need to remove the previous windows elements(indices)*/

        while (!q.empty() && q.front() <= i - k)
            q.pop_back();

        /*similarily to previous steps we'll do it for the next window k*/

        while (!q.empty() && arr[i] >= arr[q.back()])
        {
            q.pop_back();
        }
        /*push the maximum element(index) of the window*/

        q.push_back(i);
        // push all the maximums discovered but remember we are dealing with indices in deque.

        MaximumOfEachWindow.push_back(arr[q.front()]);
    }

    for (auto each : MaximumOfEachWindow)
    {
        cout << each << " ";
    }
}