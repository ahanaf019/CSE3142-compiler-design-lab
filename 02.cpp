#include<bits/stdc++.h>

using namespace std;

void countVowelsConsonants(string str);
void vowelsConsonants(string str);
void divide(string str);


int main()
{
    string str = "Munmun is the student of Computer Science & Engineering";

    countVowelsConsonants(str);
    vowelsConsonants(str);
    divide(str);

    return 0;
}


void countVowelsConsonants(string str)
{
    int vowels = 0;
    int consonants = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i'|| str[i] == 'o'|| str[i] == 'u'|| str[i] == 'A'|| str[i] == 'E'|| str[i] == 'I'|| str[i] == 'O'|| str[i] == 'U')
                vowels += 1;
            
            else 
                consonants += 1;
        }
    }

    printf("Vowel Count: %d\n", vowels);
    printf("Consonant Count: %d\n\n", consonants);
}


void vowelsConsonants(string str)
{
    int arr[200] = {0};

    for(int i = 0; str[i] != '\0'; i++)
    {
        arr[str[i]]++;
    }

    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    cout<<"Vowels Present: "<<endl;
    for(int i = 0; i < 10; i++)
    {
        if(arr[vowels[i]] > 0)
            cout<<vowels[i]<<" ";
    }
    cout<<endl;

    cout<<"Consonants Present:"<<endl;
    for(int i = 'a'; i <= 'z'; i++)
    {
        if(!(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u'))
            if(arr[i] > 0) 
                cout<<char(i)<<" ";

    }

    for(int i = 'A'; i <= 'Z'; i++)
    {
        if(!(i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U'))
            if(arr[i] > 0) 
                cout<<char(i)<<" ";

    }
    cout<<endl;
    cout<<endl;
}

void divide(string str)
{
    string vstr = "";
    string cstr = "";

    str = " " + str;

    for(int i = 1; str[i] != '\0'; i++)
    {
        if(str[i] != ' ' && str[i - 1] == ' ')
        {
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i'|| str[i] == 'o'|| str[i] == 'u'|| str[i] == 'A'|| str[i] == 'E'|| str[i] == 'I'|| str[i] == 'O'|| str[i] == 'U')
            {
                int j;
                for(j = i; str[j] != '\0'; j++)
                {   
                    if(str[j] == ' ') break;
                    vstr = vstr + str[j];
                }
                i = j;
                vstr = vstr + " ";
            }

            else
            {
                int j;
                for(j = i; str[j] != '\0'; j++)
                {   
                    if(str[j] == ' ') break;
                    cstr = cstr + str[j];
                }
                i = j;
                cstr = cstr + " ";
            }
        }

    }
    cout<<"Words start with consonant: "<<endl;
    cout<<cstr<<endl<<endl;

    cout<<"Words start with vowel: "<<endl;
    cout<<vstr<<endl;




}