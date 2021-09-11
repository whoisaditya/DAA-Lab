#include <iostream>

using namespace std;

int max_id, min_id;

struct student
{
    char name[50];
    char regno[20];
    int marks;
};

void input(struct student list[100], int n)
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

void find_max_min(struct student array[100], int l, int h, int &min, int &max)
{
    // If the array has a single element
    if (l == h) // common Comparison
    {
        if (max < array[l].marks)
        { // First Comparison
            max = array[l].marks;
            max_id = l;
        }

        if (min > array[h].marks)
        { // Second Comparison
            min = array[h].marks;
            min_id = h;
        }

        return;
    }

    // If the array has two elements

    if (h - l == 1) // Common Comparison
    {
        if (array[l].marks < array[h].marks) // First Comparison
        {
            if (min > array[l].marks)
            { // Second Comparison
                min = array[l].marks;
                min_id = l;
            }

            if (max < array[h].marks)
            { // Third Comparison
                max = array[h].marks;
                max_id = h;
            }
        }
        else
        {
            if (min > array[h].marks)
            { // Second Comparison
                min = array[h].marks;
                min_id = h;
            }

            if (max < array[l].marks)
            { // Third Comparison
                max = array[l].marks;
                max_id = l;
            }
        }
        return;
    }

    // Calcuting the middle element
    int middle = (l + h) / 2;

    // Going through the left subarray
    find_max_min(array, l, middle, min, max);

    // Going through the right subarray
    find_max_min(array, middle + 1, h, min, max);
}

int main()
{
    struct student list[100];
    int n;

    cout << "Number of students: ";
    cin >> n;

    input(list, n);

    int max = INT_MIN, min = INT_MAX;

    find_max_min(list, 0, n - 1, min, max);

    // Printing max

    cout << "The student with maximum marks" << endl;
    cout << "Name: " << list[max_id].name << endl;
    cout << "Registration No. : " << list[max_id].regno << endl;
    cout << "Marks: " << list[max_id].marks << endl;
    cout << endl;

    // Printing min

    cout << "The student with minimum marks" << endl;
    cout << "Name: " << list[min_id].name << endl;
    cout << "Registration No. : " << list[min_id].regno << endl;
    cout << "Marks: " << list[min_id].marks << endl;

    return 0;
}
