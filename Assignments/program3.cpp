// # Assignment-3
// # Application of Stack
// # Infix to Postfix conversion
#include <iostream>
using namespace std;

// # Structure
struct stack
{
    int size;
    int top;
    char *arr;
};

// # Peek
char stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

// # Empty
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// # Full
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// # Push
void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        cout << "Stack Overflow! Cannot push " << val << " to the stack " << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

// # Pop
char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack Underflow! Cannot pop from the stack" << endl;
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// # Precedence
int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

// # Operator
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else
        return 0;
}

// # Conversion Function
char *InfixToPostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // Track infix traversal
    int j = 0; // Track postfix addition
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

// # Main Function
int main()
{
    char infix[30];
    cout << "\n\t------------------------";
    cout << "\n\t| # Infix To Postfix # |\n";
    cout << "\t------------------------" << endl;
    cout << "\n\t# Enter Infix Expression: ";
    cin >> infix;
    // char *infix[] = "x-y/z-k*d";  // Fixed Input
    cout << "\n\t# The Infix Expression: " << infix << endl;
    cout << "\n\t# The Postfix Expression: " << InfixToPostfix(infix) << endl;
    cout << endl;
    return 0;
}
