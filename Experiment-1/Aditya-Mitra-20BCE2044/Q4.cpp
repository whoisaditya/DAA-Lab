/* A Naive recursive implementation of
0-1 Knapsack problem */
#include <iostream>
using namespace std;

// A utility function that returns maximum of two integers
int max(float a, float b) { return (a > b) ? a : b; }

struct Knapsack {
    int weight;
    float value;
};

void input(struct Knapsack arr[100], int n)
{
    cout << "Enter "<< n <<" weights and values"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"Item "<< i <<endl;
        cout<< "Weight: ";
        cin >> arr[i].weight; 
        cout<< "Value: ";
        cin >> arr[i].value;
        cout<<endl;
    }
}

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, struct Knapsack arr[100], int n)
{

    // Base Case
    if (n == 0 || W == 0)
    {
        return 0;
    }

    /*
     If weight of the nth item is more
     than Knapsack capacity W, then
     this item cannot be included
     in the optimal solution
     */

    if (arr[n - 1].weight > W)
    {
        return knapSack(W, arr, n - 1);
    }

    /* 
    Return the maximum of two cases:
    (1) nth item included
    (2) not included 
    */
    else
    {
        return max(
            arr[n-1].value + knapSack(W - arr[n-1].weight,
                                  arr, n-1),
            knapSack(W, arr, n-1));
    }
}

// Driver code
int main()
{
    Knapsack arr[100];

    int n;
    cout << "Enter the no. of inputs: ";
    cin >> n;

    input(arr, n);

    int capacity;
    cout << "Enter capacity: ";
    cin >> capacity;

    cout << "Value in the Knapsack: "<< knapSack(capacity, arr, n);

    return 0;
}

