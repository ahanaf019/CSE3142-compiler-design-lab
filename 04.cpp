#include<bits/stdc++.h>

using namespace std;

bool intVar(string str);
bool longInt(string str);
bool shortInt(string str);

int main()
{
    string str = "9990";

    cin>>str;

    if(intVar(str))
    cout<<"Integer Variable"<<endl;

    else if(shortInt(str))
    cout<<"Short Integer"<<endl;

    else if(longInt(str))
    cout<<"Long Integer"<<endl;

    else
    cout<<"Invalid input"<<endl;


    return 0;
}

bool intVar(string str)
{
    if(!((str[0]>='i' && str[0] <= 'n')||(str[0]>='I' && str[0] <= 'N')))
        return false;

    int length = str.length();

    for(int i = 1; str[i] != '\0'; i++)
    {
        if(!((str[i]>='a' && str[i] <= 'z') || (str[i]>='A' && str[i] <= 'Z') || (str[i]>='0' && str[i] <= '9')))
            return false;
    }
    return true;
}

bool shortInt(string str)
{
    if(str.length() > 4) return false;

    if(!(str[0] >= '1' && str[0] <= '9')) return false;

    for(int i = 1; str[i] != '\0'; i++)
    {
        if(!(str[i] >= '0' && str[i] <= '9')) return false;
    }

    return true;
}

bool longInt(string str)
{
    if(str.length() < 5) return false;

    if(!(str[0] >= '1' && str[0] <= '9')) return false;

    for(int i = 1; str[i] != '\0'; i++)
    {
        if(!(str[i] >= '0' && str[i] <= '9')) return false;
    }

    return true;
}