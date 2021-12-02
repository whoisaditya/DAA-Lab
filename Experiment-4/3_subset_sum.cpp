#include <iostream>
using namespace std;

class Subset_Sum
{
public:
    int size;
    int *set;
    int sum;
    int *sub_set;

    void display_sub_set(int );
    void sub_set_sum(int , int , int );
    void find_sub_set();
};

void Subset_Sum::display_sub_set(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << sub_set[i] << "  ";
    }
    cout << endl;
}

void Subset_Sum::sub_set_sum(int sub_size, int total, int node_count)
{
    if (total == sum)
    {
         //print the sub set
        display_sub_set(sub_size);

        //for other sub sets                                                     
        sub_set_sum(sub_size - 1, total - set[node_count], node_count + 1); 

        return;
    }
    else
    {
        for (int i = node_count; i < size; i++)
        {   
            //find node along breadth
            sub_set[sub_size] = set[i];
            sub_set_sum(sub_size + 1, total + set[i], i + 1); //do for next node in depth
        }
    }
}

void Subset_Sum::find_sub_set()
{
    int *sub_set = new int[size]; //create sub_set array to pass parameter of sub_set_sum

    sub_set_sum(0, 0, 0);

    delete[] sub_set;
}

int main()
{
    cout << "Name: Aditya Mitra" << endl;
    cout << "Reg. No. 20BCE2044\n" << endl;

    Subset_Sum obj;

    cout << "Enter the size of the set: ";
    cin >> obj.size;

    cout << "Enter the set: ";
    obj.set = new int[obj.size];
    for (int i = 0; i < obj.size; i++)
    {
        cin >> obj.set[i];
    }

    cout << "Enter the sum: ";  
    cin >> obj.sum;

    cout << "\nThe possible subsets are: " << endl;
    obj.find_sub_set();
}