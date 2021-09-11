// Second Smallest and Second Largest

#include <iostream>

using namespace std;

struct student
{
    string name;
    string  regno;
    int marks;
};

void input(struct student list[50], int n)
{
    cout << "Enter the list of students" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Name: ";
        cin >> list[i].name;

        cout << "Registration No. : ";
        cin >> list[i].regno;

        cout << "Marks: ";
        cin >> list[i].marks;

        cout << endl;
    }
}

void swap(struct student arr[100], int i, int j)
{
    int temp_marks;

    arr[i].regno.swap(arr[j].regno);
    arr[i].name.swap(arr[j].name);

    temp_marks = arr[j].marks; 
    arr[j].marks = arr[i].marks;
    arr[i].marks = temp_marks;


}

void sorting(struct student arr[100], int size)
{
    for (int i = 0; i < size; i++) //Sorting Array
    {
        int temp;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i].marks > arr[j].marks)
            {
                swap(arr, i, j);
            }
        }
    }
}

int main()
{
    struct student list[100];
    int n;

    cout << "Number of students: ";
    cin >> n;

    input(list, n);

    sorting(list, n);

    // Printing second max

    cout << "The student with second maximum marks" << endl;
    cout << "Name: " << list[n-2].name << endl;
    cout << "Registration No. : " << list[n-2].regno << endl;
    cout << "Marks: " << list[n-2].marks << endl;
    cout << endl;

    // Printing second min

    cout << "The student with second minimum marks" << endl;
    cout << "Name: " << list[1].name << endl;
    cout << "Registration No. : " << list[1].regno << endl;
    cout << "Marks: " << list[1].marks << endl;            
    return 0;
}