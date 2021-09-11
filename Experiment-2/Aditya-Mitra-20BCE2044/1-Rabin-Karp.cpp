// Following program is a C++ implementation of Rabin Karp

#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

// d is the number of characters in the input alphabet
#define d 256

class Rabin_Karp
{
public:
    void search(char[], char[], int);
    //int calc_hash(char[], int, int);
};

/* 
pat -> pattern
	txt -> text
	q -> A prime number
*/

//Calculate the hash value of pattern 

int  calc_hash(char str[], int M, int q)
{
    int n;

    for (int i = 0; i < M; i++)
    {
        n = (d * n + str[i]) % q;
    }

    return n;
}

void Rabin_Karp::search(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    //cout<<M<<endl;
    int N = strlen(txt);
    //cout<<N<<endl;

    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
    {
        h = (h * d) % q;
    }

/*
    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
    */

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {

        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters one by one
        if (p == t)
        {
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[i + j] != pat[j])
                {
                    break;
                }
            }

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M)
            {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            // We might get negative value of t, converting it
            // to positive
            if (t < 0)
            {
                t = (t + q);
            }
        }
    }
}

/* Driver code */
int main()
{
    Rabin_Karp obj;

    char txt[50]; //= "AdityaisreallycoolandAdityalikestocode";
    char pat[10]; // = "Adi";

    cout << "Enter the string: ";
    cin >> txt;

    cout << "Enter the pattern String: ";
    cin >> pat;

    int q; // = 101
    cout << "Enter a Prime Number: ";
    cin >> q;

    // Function Call
    obj.search(pat, txt, q);

    return 0;
}
