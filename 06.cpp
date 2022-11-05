#include<bits/stdc++.h>

using namespace std;

bool charVar(string str);
bool binaryVar(string str);
bool binaryNum(string str);

int main()
{
    string str = "0";

    cin>>str;

    if(charVar(str))
        cout<<"Character Variable"<<endl;

    else if(binaryVar(str))
        cout<<"Binary Variable"<<endl;

    else if(binaryNum(str))
        cout<<"Binary Number"<<endl;
    
    else cout<<"Invalid"<<endl;

    return 0;
}


bool charVar(string str)
{
    if(str.length() < 4) return false;

    if(!(str[0]=='c' && str[1]=='h' && str[2]=='_')) return false;

    if(!((str[3] >= 'a' && str[3] <= 'z') || (str[3] >= 'A' && str[3] <= 'Z') || (str[3] >= '0' && str[3] <= '9'))) return false;

    for(int i = 4; str[i] != '\0'; i++)
    {
        if(!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))) return false;
    }
    
    return true;    
}

bool binaryVar(string str)
{
    if(str.length() < 4) return false;

    if(!(str[0]=='b' && str[1]=='n' && str[2]=='_')) return false;

    if(!((str[3] >= 'a' && str[3] <= 'z') || (str[3] >= 'A' && str[3] <= 'Z') || (str[3] >= '0' && str[3] <= '9'))) return false;

    for(int i = 4; str[i] != '\0'; i++)
    {
        if(!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))) return false;
    }
    
    return true;    
}

bool binaryNum(string str)
{
    if(str.length() < 2) return false;

    if(!(str[0] == '0')) return false;

    for(int i = 1; str[i] != '\0'; i++)
    {
        if(!(str[i] == '0' || str[i] == '1')) return false;
    }

    return true;
}