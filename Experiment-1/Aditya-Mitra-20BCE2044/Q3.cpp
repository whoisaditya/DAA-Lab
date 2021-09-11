// C++ implementation of Karatsuba algorithm for bit string multiplication.
#include <iostream>

using namespace std;

class Karastuba
{
public:
    int make_equal_length(string &, string &);

    string add_bit_strings(string, string);

    int multiply_single_bit(string, string);

    long int multiply(string, string);

    void dec_to_binary(int);
};

int Karastuba ::make_equal_length(string &string_1, string &string_2)
{
    int length_1 = string_1.size();
    int length_2 = string_2.size();

    if (length_1 < length_2)
    {
        for (int i = 0; i < length_2 - length_1; i++)
        {
            string_1 = '0' + string_1;
        }
        return length_2;
    }
    else if (length_1 > length_2)
    {
        for (int i = 0; i < length_1 - length_2; i++)
        {
            string_2 = '0' + string_2;
        }
    }
    return length_1; // If length_1 >= length_2
}

// The main function that adds two bit sequences and returns the addition
string Karastuba ::add_bit_strings(string first, string second)
{
    string result; // To store the sum bits

    // make the lengths same before adding
    int length = make_equal_length(first, second);
    int carry = 0; // Initialize carry

    // Add all bits one by one
    for (int i = length - 1; i >= 0; i--)
    {
        int firstBit = first.at(i) - '0';
        int secondBit = second.at(i) - '0';

        // boolean expression for sum of 3 bits
        int sum = (firstBit ^ secondBit ^ carry) + '0';

        result = (char)sum + result;

        // boolean expression for 3-bit addition
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }

    // if overflow, then add a leading 1
    if (carry)
    {
        result = '1' + result;
    }

    return result;
}

// A utility function to multiply single bits of strings a and b
int Karastuba ::multiply_single_bit(string a, string b)
{
    return (a[0] - '0') * (b[0] - '0');
}

// The main function that multiplies two bit strings X and Y and returns result as long integer
long int Karastuba ::multiply(string X, string Y)
{
    // Find the maximum of lengths of x and Y and make length of smaller string same as that of larger string
    int length = make_equal_length(X, Y);

    // Base cases
    if (length == 0)
    {
        return 0;
    }
    if (length == 1)
    {
        return multiply_single_bit(X, Y);
    }

    int first_half = length / 2;             // First half of string, floor(length/2)
    int second_half = (length - first_half); // Second half of string, ceil(length/2)

    // Find the first half and second half of first string.

    string Xl = X.substr(0, first_half);
    string Xr = X.substr(first_half, second_half);

    // Find the first half and second half of second string
    string Yl = Y.substr(0, first_half);
    string Yr = Y.substr(first_half, second_half);

    // Recursively calculate the three products of inputs of size length/2
    long int P1 = multiply(Xl, Yl);
    long int P2 = multiply(Xr, Yr);
    long int P3 = multiply(add_bit_strings(Xl, Xr), add_bit_strings(Yl, Yr));

    // Combine the three products to get the final result.
    return P1 * (1 << (2 * second_half)) + (P3 - P1 - P2) * (1 << second_half) + P2;
}

void Karastuba ::dec_to_binary(int length)
{
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (length > 0)
    {

        // storing remainder in binary array
        binaryNum[i] = length % 2;
        length = length / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
    {
        cout << binaryNum[j];
    }
}

// Driver program to test above functions
int main()
{

    string n1, n2;
    Karastuba obj;

    cout << "Enter the binary numbers you want to multiply" << endl;

    cout << "First Number: ";
    cin >> n1;

    cout << "Second Number: ";
    cin >> n2;

    int result = obj.multiply(n1, n2);

    cout << "Result " << endl;
    cout << "Decimal No: " << result << endl;
    cout << "Binary No: ";
    obj.dec_to_binary(result);
}
