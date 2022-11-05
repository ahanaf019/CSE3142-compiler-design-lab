#include<bits/stdc++.h>

using namespace std;

bool floatVar(string str);
bool doubleNum(string str);
bool floatNum(string str);

int main()
{
    string str = "0.1001";

    // cin>>str;

    if(floatVar(str))
    cout<<"Float Variable"<<endl;

    else if(floatNum(str))
    cout<<"Float Number"<<endl;

    else if(doubleNum(str))
    cout<<"Double Number"<<endl;

    else
    cout<<"Invalid input"<<endl;


    return 0;
}

bool floatVar(string str)
{
    if(!((str[0]>='a' && str[0] <= 'h')||(str[0]>='A' && str[0] <= 'H') || (str[0]>='o' && str[0] <= 'Z')||(str[0]>='O' && str[0] <= 'Z')))
        return false;

    int length = str.length();

    for(int i = 1; str[i] != '\0'; i++)
    {
        if(!((str[i]>='a' && str[i] <= 'z') || (str[i]>='A' && str[i] <= 'Z') || (str[i]>='0' && str[i] <= '9')))
            return false;
    }
    return true;
}

bool floatNum(string str)
{
    int count = 0;
    int pos = -1;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == '.') 
        {
            count += 1;
            pos = i;
        }
    }

    if(count != 1) return false;

    if(pos == 0) return false;

    if(pos != str.length() - 3) return false;


    if(pos == 1)
    {
        if(!(str[0] >= '0' && str[0] <= '9')) return false;
    }

    else 
    {
        if(!(str[0] >= '1' && str[0] <= '9')) return false;
        
        for(int i = 1; i < pos; i++)
        {
            if(!(str[i] >= '0' && str[i] <= '9')) return false;
        }
    }

    for(int i = pos + 1; str[i] != '\0'; i++)
    {
        if(!(str[i] >= '0' && str[i] <= '9')) return false;
    }

    return true;
}

bool doubleNum(string str)
{
    int count = 0;
    int pos = -1;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == '.') 
        {
            count += 1;
            pos = i;
        }
    }

    if(count != 1) return false;

    if(pos == 0) return false;

    if(pos == 1)
    {
        if(!(str[0] >= '0' && str[0] <= '9')) return false;
    }

    else 
    {
        if(!(str[0] >= '1' && str[0] <= '9')) return false;
        
        for(int i = 1; i < pos; i++)
        {
            if(!(str[i] >= '0' && str[i] <= '9')) return false;
        }
    }

    for(int i = pos + 1; str[i] != '\0'; i++)
    {
        if(!(str[i] >= '0' && str[i] <= '9')) return false;
    }

    return true;
}