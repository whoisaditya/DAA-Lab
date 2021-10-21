#include <cstdio>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Point
{
public:
    int x, y;

    bool operator<(Point b)
    {
        if (y != b.y)
        {
            return y < b.y;
        }
        return x < b.x;
    }
    
};

Point pivot;

int ccw(Point a, Point b, Point c)
{
    int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0)
    {
        return -1;
    }
    else if (area < 0)
    {
        return 1;
    }
    return 0;
}

int sqrDist(Point a, Point b)
{
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

bool POLAR_ORDER(Point a, Point b)
{
    int order = ccw(pivot, a, b);
    if (order == 0)
    {
        return sqrDist(pivot, a) < sqrDist(pivot, b);
    }
    return (order == -1);
}

stack<Point> grahamScan(Point *points, int N)
{
    stack<Point> Hull;

    if (N < 3)
    {
        return Hull;
    }

    int least_Y = 0;
    for (int i = 1; i < N; i++)
    {
        if (points[i] < points[least_Y])
        {
            least_Y = i;
        }
    }

    Point temp = points[0];
    points[0] = points[least_Y];
    points[least_Y] = temp;

    pivot = points[0];
    sort(points + 1, points + N, POLAR_ORDER);

    Hull.push(points[0]);
    Hull.push(points[1]);
    Hull.push(points[2]);

    for (int i = 3; i < N; i++)
    {
        Point top = Hull.top();
        Hull.pop();
        while (ccw(Hull.top(), top, points[i]) != -1)
        {
            top = Hull.top();
            Hull.pop();
        }
        Hull.push(top);
        Hull.push(points[i]);
    }
    return Hull;
}

int main()
{
    int N;

    cout << "Aditya Mitra 20BCE2044"<< endl;
    cout << endl;

    cout << "Enter the number of points: ";
    cin >> N;

    cout << endl;

    Point *points = new Point[N];

    for (int i = 0; i < N; i++)
    {
        cout << "Point " << i+1 << " :" << endl;

        cout << "X: ";
        cin >> points[i].x;
        
        cout << "Y: ";
        cin >> points[i].y;

        cout << endl;
    }

    stack<Point> Hull = grahamScan(points, N);

    cout << "Output: " << endl;
    while (!Hull.empty())
    {
        Point p = Hull.top();
        Hull.pop();

        cout << "( " << p.x << " , " << p.y << " )" <<endl;
    }
    return 0;
}