// # Reverse string using stack
#include <iostream>
using namespace std;

// Global declaration
char *str;
int N, top = -1;

// Function declaration
void Push(void);
void Reverse(void);

// main function
int main()
{
    cout << "\n# Reverse string using stack #" << endl;
    cout << "Enter size of the string: ";
    cin >> N;
    str = new (nothrow) char[N];
    Push();
    Reverse();
    return 0;
}

// ** Function defination **

// # Push
void Push()
{
    char s;
    cout << "* Enter string: ";
    for (int i = 0; i < N; i++)
    {
        top++;
        cin >> s;
        str[top] = s;
    }
}

// # Reverse
void Reverse()
{

    cout << "* Reversed string: ";
    for (int i = top; i >= 0; i--)
    {
        cout << str[i];
    }
    cout << endl;
}