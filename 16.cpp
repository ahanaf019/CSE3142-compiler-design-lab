#include<bits/stdc++.h>

using namespace std;

void infToPostfix(string str);
int precedence(char c1);


int main()
{
    string str = "x^y/(5*z)+2";

    infToPostfix(str);

    return 0;
}


void infToPostfix(string str)
{
    stack<char> stk;

    stk.push('(');
    str = str + ")";

    int i = 0;

    while(str[i] != '\0')
    {
        char top = stk.top();

        if(str[i] == '(')
            stk.push(str[i]);

        else if(str[i] == ')')
        {
            while(stk.top() != '(')
            {
                cout<<stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9'))
        {
            cout<<str[i];
        }

        else
        {
            while(!stk.empty() && (precedence(stk.top()) > precedence(str[i])))
            {
                cout<<stk.top();
                stk.pop();
            }
            stk.push(str[i]);
        }

        i += 1;
    }
    cout<<endl;

}


int precedence(char c1)
{
    if(c1 == '^') return 3;
    if(c1 == '*') return 2;
    if(c1 == '/') return 2;
    if(c1 == '+') return 1;
    if(c1 == '-') return 1;
    else return -1;
}

