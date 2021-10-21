#include <bits/stdc++.h>
using namespace std;

class LCS
{

public:
	LCS(int, int);

	int **arr;

	char* result;

	int max(int, int);

	int lcs(string, string, int, int);
};

LCS::LCS(int m, int n)
{
	arr = new int *[m + 1];

	for (int i = 0; i <= m; i++)
	{
		arr[i] = new int[n + 1];
		for (int j = 0; j <= n; j++)
		{
			arr[i][j] = 0;
		}
	}
}
// Utility function to get max of 2 integers
int LCS::max(int a, int b)
{
	return (a > b) ? a : b;
}

// Returns length of LCS
int LCS::lcs(string X, string Y, int m, int n)
{
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
			{
				arr[i][j] = 0;
			}

			else if (X[i - 1] == Y[j - 1])
			{
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else
			{
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}

	// Following code is used to print LCS
	int index = arr[m][n];

	// Start from the right-most-bottom-most corner and one by one store characters in  
	result = new char[index+1];
	int i = m, j = n;
	while (i > 0 && j > 0)
	{
		if (X[i - 1] == Y[j - 1])
		{
			result[index - 1] = X[i - 1]; // Put current character in result
			i--;
			j--;
			index--; // reduce values of i, j and index
		}

		else if (arr[i - 1][j] > arr[i][j - 1])
		{
			i--;
		}
		else
		{
			j--;
		}
	}

	return arr[m][n];
}


// Driver code
int main()
{
	string X;
	string Y;

	cout << "Aditya Mitra 20BCE2044\n"
		 << endl;

	cout << "The main string: ";
	cin >> X;

	cout << "The sub string: ";
	cin >> Y;

	int m = X.length();
	int n = Y.length();

	LCS obj(m, n);

	cout << "\nThe length of LCS is " << obj.lcs(X, Y, m, n) << endl;

	cout << "The LCS: " << obj.result << endl;

	cout << "\nLCS Table:" << endl;

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			cout << obj.arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
