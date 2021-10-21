#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

class KMP
{
    public:
        int cnt;
        KMP();
        void prefix_suffix_array(char *, int, int *);
        void kmp(char *, char *);
};

KMP::KMP()
{
    cnt = 0;
}

void KMP::prefix_suffix_array(char *pattern_string, int M, int *pps)
{
    int length = 0;
    pps[0] = 0;
    int i = 1;

    while (i < M)
    {
        if (pattern_string[i] == pattern_string[length])
        {
            length++;
            pps[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
            {
                length = pps[length - 1];
            }
            else
            {
                pps[i] = 0;
                i++;
            }
        }
    }
}

void KMP::kmp(char *main_string, char *pattern_string)
{
    int M = strlen(pattern_string);
    int N = strlen(main_string);

    int pps[M];

    prefix_suffix_array(pattern_string, M, pps);
    int i = 0, j = 0;

    

    while (i < N)
    {
        if (pattern_string[j] == main_string[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
            printf("Found pattern_string at index %d\n", i - j);
            j = pps[j - 1];
            cnt++;
        }
        else if (i < N && pattern_string[j] != main_string[i])
        {
            if (j != 0)
            {
                j = pps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
}

int main()
{
    char main_string[50];
    char pattern_string[50];

    KMP obj;

    cout<<"Aditya Mitra 20BCE2044\n" << endl;

    cout << "Enter the Main String: ";
    cin >> main_string;

    cout << "Enter the Pattern String: ";
    cin >> pattern_string;

    cout << endl;

    obj.kmp(main_string, pattern_string);

    cout << "\n\nNo. of times the pattern was found: " << obj.cnt << endl;

    return 0;
}
