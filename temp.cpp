#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct person
{
    double marks;
    char name[20];
    char registrationnumber[10];
};

void minmaxfinder(struct person A[50], int i, int j, double *min, double *max)

{
    if (i == j)
    {
        *max = A[i].marks;
        *min = A[i].marks;
        return;
    }
    if (i + 1 == j)
    {
        if (A[i].marks > A[j].marks)
        {
            *min = A[j].marks;
            *max = A[i].marks;
        }
        else
        {
            *max = A[j].marks;
            *min = A[i].marks;
        }
        return;
    }
    int mid = (i + j) / 2;
    double min1 = INFINITY;
    double min2 = INFINITY;
    double max1 = (-1) * INFINITY;
    double max2 = (-1) * INFINITY;

    minmaxfinder(A, i, mid, &min1, &max1);
    minmaxfinder(A, mid + 1, j, &min2, &max2);

    *min = (min1 < min2) ? min1 : min2;
    *max = (max1 > max2) ? max1 : max2;

    return;
}

int main()
{
    int n;
    printf("\n Enter total number of persons: ");
    scanf("%d", &n);

    struct person st[50];

    for (int i = 0; i < n; i++)
    {
        printf("\n Enter the details of person %d in this order 'Registration Number Name Marks: ", i + 1);
        scanf("%s %s %d", st[i].registrationnumber, st[i].name, &st[i].marks);
    }
    double min = INFINITY;
    double max = (-1) * INFINITY;

    minmaxfinder(st, 0, n - 1, &min, &max);
    printf("\nMinimum Value \t %f ", min);
    printf("\nMaximum Value \t %f ", max);
    return 0;
}