/*
Accept the file size from the user and store them in m, n respectively.
Create an array named files using m, n
Define merge_cost to find the cost of merging the files.
Create a min heap using priority queues
Define a vatiable count to count the total computation
pop two smallest size element from the min heap
Add the current computations with the previous one's
Add new combined file size to priority queue or min heap
*/

// C++ program to implement
// Optimal File Merge Pattern
#include <bits/stdc++.h>
using namespace std;

int merge_cost(int size, int files[])
{
    // Create a min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < size; i++)
    {

        // Add sizes to priorityQueue
        pq.push(files[i]);
    }

    // Variable to count total Computation
    int count = 0;

    while (pq.size() > 1)
    {
        // pop two smallest size element
        // from the min heap
        int first_smallest = pq.top();
        pq.pop();
        int second_smallest = pq.top();
        pq.pop();

        int temp = first_smallest + second_smallest;

        // Add the current computations
        // with the previous one's
        count += temp;

        // Add new combined file size
        // to priority queue or min heap
        pq.push(temp);
    }
    return count;
}

// Driver code
int main()
{

    // No of files
    int N = 2;
    int m, n;
    cout << "Enter the size of files: \n";
    cout << "Enter the size of file 1: ";
    cin >> m;
    cout << "Enter the size of file 2: ";
    cin >> n;

    int files[N] = {m, n};

    // Total no of computations
    // do be done final answer
    cout << "Minimum Computations = "
         << merge_cost(N, files);

    return 0;
}

