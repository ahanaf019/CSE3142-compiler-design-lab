#include<bits/stdc++.h>

using namespace std;

int precedence(char c1);
void infToPostfix(string str);
// void solve(string str, string tmp, int i);
void solve(string str);


bool els = false;

int main()
{
    // string str = "if a then if c-d then a+c else a*c else a+b";
    string str = "if a then if c-d then a+c else if b then q else a+b";
    // string str = "if a-b+c then d";

    solve(str);
    // solve(str, "", 0);


    return 0;
}

void solve(string str)
{
    string tmp = "";
    string res = "";

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ') continue;

        tmp = tmp + str[i];

        if(tmp == "if")
        {
            tmp = "";
        }

        if(tmp.length() > 4)
        {
            int len = tmp.length();
            if(tmp.find("then") != -1)
            {
                tmp.erase(len - 4);    
                res = res + tmp + " ";
                infToPostfix(tmp);
                tmp = "";
            
            }

            else if(tmp.find("else") != -1)
            {
                tmp.erase(len - 4);    
                res = res + tmp + " ";
                infToPostfix(tmp);
                els = true;
                tmp = "";
                // cout<<"?";
            }
        }
    }
    res = res + tmp;
    infToPostfix(tmp);
    cout<<endl;
    cout<<res<<endl;

}


// void solve(string str, string tmp, int i)
// {
//     if(str[i] == '\0') return;

//     if(str[i] == ' ') solve(str, tmp, i+1);

//     if(tmp == "if")
//         solve(str, "", i+1);

    
    
// }


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

    if(els) 
    {
        cout<<"?";
        els = false;
    }
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
