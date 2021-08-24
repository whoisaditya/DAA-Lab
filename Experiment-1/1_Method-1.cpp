#include <iostream>
using namespace std;

struct student
{
    char name[50];
    char regno[20];
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

void find_min_max(struct student list[50], int n)
{
    int min, max;
    int min_id, max_id;

    min = INT_MAX;
    max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (list[i].marks > max)
        {
            max_id = i;
        }

        if (list[i].marks < min)
        {
            min_id = i;
        }
    }

    // Printing max

    cout << "The student with maximum marks" << endl;
    cout << "Name: " << list[max_id].name << endl;
    cout << "Registration No. : " << list[max_id].regno << endl;
    cout << "Marks: "<< list[max_id].marks << endl;
    cout << endl;

    // Printing min

    cout << "The student with minimum marks" << endl;
    cout << "Name: " << list[min_id].name << endl;
    cout << "Registration No. : " << list[min_id].regno << endl;
    cout << "Marks: "<< list[min_id].marks << endl;

}

int main()
{
    struct student list[50];
    int n;

    cout << "Number of students: ";
    cin >> n;

    input(list, n);

    find_min_max(list, n);

    return 0;
}
