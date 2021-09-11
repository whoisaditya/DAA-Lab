#include <iostream>

using namespace std;

struct Knapsack {
    int weight;
    float value;
    float ratio;
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

void calculate_ratio(struct Knapsack arr[100], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i].ratio = arr[i].value / arr[i].weight;
    }
}

void sorting(struct Knapsack arr[100], int n)
{
    for (int i = 0; i < n; i++)
    {
        float temp;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j].ratio > arr[i].ratio)
            {
                temp = arr[j].ratio;
                arr[j].ratio = arr[i].ratio;
                arr[i].ratio = temp;

                temp = arr[j].weight;
                arr[j].weight = arr[i].weight;
                arr[i].weight = temp;

                temp = arr[j].value;
                arr[j].value = arr[i].value;
                arr[i].value = temp;
            }
        }
    }

}

void print_solution(struct Knapsack arr[100], int n)
{
    for(int i = 0; i < n; i++)
    {

    }
}

int main()
{
    Knapsack arr[100];

    int n, capacity, current_weight = 0, i = 0;
    float current_value = 0.0;

    cout << "Enter the no. of inputs: ";
    cin >> n;

    input(arr, n);
    calculate_ratio(arr, n);
    sorting(arr, n);

    cout << "Enter capacity: ";
    cin >> capacity;

    while (current_weight + arr[i].weight <= capacity)
    {
        if (i >= n)
        {
            break;
        }
        current_weight += arr[i].weight;
        current_value += arr[i].value;
        i++;
    }

    int leftover = capacity - current_weight;
    current_value += leftover * arr[i].value / arr[i].weight;

    float ratio_1 = leftover*100/arr[i].weight;
    cout<<"Considered Percentage " <<  ratio_1 << "%, Value "<<arr[i].value << ", Weight: " << arr[i].weight << endl;

    cout << "Value in the Knapsack: "<<current_value;
}