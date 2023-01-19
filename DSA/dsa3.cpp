#include <iostream>
using namespace std;
int chechpresidence(char a)
{
    if (a == '+' || a == '-')
    {
        return 1;
    }
    else if (a == '*' || a == '/')
    {
        return 2;
    }
    else if (a == '^')
    {
        return 3;
    }
    else
    {
        return -1;
    }
}
class stack
{

public:
    int top = -1;
    string st;
    stack()
    {}

    void push(char exp)
    {
        top++;
        st[top]=exp;
    }

    void pop()
    {
        st[top]='\0';
        top--;
    }
    int empty()
    {
        if(st[0]=='\0')
        return 0;
        else 
        return 1;
    }
    friend void infix_postfix(string );
};

void infix_postfix(string str)
{
    stack s;
    string result;
    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
        else if (c == '(')
        {
            s.push('(');
        }
        else if(c==')')
        {
            while(s.st[s.top]!='(')
            {
                result+=s.st[s.top];
                s.pop();
            }
            s.pop();
        }
        else 
        {
            while(s.empty() &&(chechpresidence(str[i])<=chechpresidence(s.st[s.top])))
            {
                result+=s.st[s.top];
                s.pop();
            }
            s.push(c);
        }
    }
    while(s.empty())
    {
        result+=s.st[s.top];
        s.pop();
    }
    cout<<result<<endl;
}

int main()

{
    string exp;
    cout<<"enter the expression:"<<endl;
    cin>>exp;
    infix_postfix(exp);
    return 0;
}
