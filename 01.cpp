#include<bits/stdc++.h>

using namespace std;

int countWords(string str);
int countLetters(string str);
int countSpCharacters(string str);
int countDigits(string str);
void seperate(string str);


int main()
{
    string str = "Md. Tareq Zaman, Part-3, 2011";

    cout<<"Words Count: "<<countWords(str)<<endl;
    cout<<"Letters Count: "<<countLetters(str)<<endl;
    cout<<"Digits Count: "<<countDigits(str)<<endl;
    cout<<"Special Chars Count: "<<countSpCharacters(str)<<endl;
    cout<<endl;

    seperate(str);


    return 0;
}


int countWords(string str)
{
    int count;

    str.empty() ? count = 0 : str[0] == ' ' ? count = 0: count = 1;

    for(int i = 1; str[i] != '\0'; i++)
        if(str[i-1] == ' ')
            if(str[i] != ' ')
                count += 1;


    return count;
}

int countLetters(string str)
{
    int count = 0;

    for(int i = 0; str[i] != '\0'; i++)
        if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
                count += 1;

    return count;
}


int countDigits(string str)
{
    int count = 0;

    for(int i = 0; str[i] != '\0'; i++)
        if(str[i] >= '0' && str[i] <= '9')
                count += 1;

    return count;
}


int countSpCharacters(string str)
{
    int count = 0;

    for(int i = 0; str[i] != '\0'; i++)
        if(!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')))
                count += 1;

    return count;
}



void seperate(string str)
{
    cout<<"Letters:"<<endl;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
            cout<<str[i]<<" ";
    }
    cout<<endl;

    cout<<"Digits:"<<endl;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
            cout<<str[i]<<" ";
    }
    cout<<endl;

    cout<<"Special Chars:"<<endl;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')))
        {
            if(str[i] == ' ')
                cout<<"<space> ";
            else cout<<str[i]<<" ";
        }
    }
    cout<<endl;

}

