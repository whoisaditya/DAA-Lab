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
        int cnt;
        Rabin_Karp();
        void pattern_search(char*, char*, int);
};

Rabin_Karp::Rabin_Karp()
{
    cnt = 0;
}

void Rabin_Karp::pattern_search(char pattern_string[], char main_string[], int prime)
{
    int M = strlen(pattern_string);
    int N = strlen(main_string);

    int i, j;

    int p = 0; // hash value for pattern_string
    int t = 0; // hash value for main_string
    int h = 1;

    // The value of h would be "pow(d, M-1)%prime"
    for (i = 0; i < M - 1; i++)
    {
        h = (h * d) % prime;
    }

    // Calculate the hash value
    for (i = 0; i < M; i++)
    {
        p = (d * p + pattern_string[i]) % prime;
        t = (d * t + main_string[i]) % prime;
    }

    // Slide the pattern_stringtern over text one by one
    for (i = 0; i <= N - M; i++)
    {

        // Check the hash values of current window of text and pattern_stringtern. If the hash values match then only check for characters one by one
        if (p == t)
        {
            bool flag = true;
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (main_string[i + j] != pattern_string[j])
                {
                    flag = false;
                    break;
                }
            }

            // if p == t and pattern_string[0...M-1] = main_string[i, i+1, ...i+M-1]

            if (j == M)
            {
                cnt++;
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Calculate hash value for next window of text: Remove leading digit, add trailing digit
        if (i < N - M)
        {
            t = (d * (t - main_string[i] * h) + main_string[i + M]) % prime;

            // We might get negative value of t, converting it to positive
            if (t < 0)
            {
                t = (t + prime);
            }
        }
    }
}

/* Driver code */
int main()
{
    Rabin_Karp obj;

    char main_string[50];    //= "AdityaMitra20BCE2044";
    char pattern_string[10]; // = "BCE";

    cout<<"Aditya Mitra 20BCE2044\n" << endl;
    
    cout << "Enter the Main String: ";
    cin >> main_string;

    cout << "Enter the Pattern String: ";
    cin >> pattern_string;

    int prime; 
    cout << "Enter a Prime Number: ";
    cin >> prime;

    cout << endl;

    // Function Call
    obj.pattern_search(pattern_string, main_string, prime);

    cout << "\n\nNo. of times the pattern was found: " << obj.cnt << endl;

    return 0;
}
