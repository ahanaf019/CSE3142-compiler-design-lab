#include<bits/stdc++.h>

using namespace std;



string reverse_str(string str);
void parse(string str);
void analyze_identifier(string str);
bool integer(string str);
bool identifier(string str);


map<string, string> productions;

int main()
{
    productions["E+E"] = "E";
    productions["E-E"] = "E";
    productions["E*E"] = "E";
    productions["E/E"] = "E";
    productions["(E)"] = "E";
    productions["X"] = "E";

    string str = "22*(69+((b-atc))";

    // cout<<integer("69")<<endl;
    // cout<<identifier("")<<endl;

    // parse(str);
    analyze_identifier(str);


    return 0;
}

void analyze_identifier(string str)
{
    string tmp = "";
    string res = "";
    for(int i = 0; str[i] != '\0'; i++)
    {
        // cout<<str[i]<<endl;
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(' || str[i] == ')')
        {
            // cout<<tmp<<endl;
            // cout<<str[i]<<endl;
            if(tmp != "")
            {
                if(integer(tmp) || identifier(tmp)) res += "X";
                
                else
                {
                    cout<<"INVALID"<<endl;
                    return;
                }
            }

            res = res + str[i];
            tmp = "";
        }

        else
        {
            tmp = tmp + str[i];
        }

    }

    if(tmp != "")
    {
        if(integer(tmp) || identifier(tmp)) res += "X";
        
        else
        {
            cout<<"INVALID"<<endl;
            return;
        }
    }


    cout<<res<<endl;

    parse(res);
}

bool integer(string str)
{
    if(str.length() < 1) return false;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(!(str[i] >= '0' && str[i] <= '9'))
            return false;
    }

    return true;
}

bool identifier(string str)
{
    if(str.length() < 1) return false;

    if(!(str[0] == '_' || (str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z')))
        return false;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(!(str[i] == '_' || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[0] >= 'a' && str[i] <= '9')))
            return false;
    }

    return true;
}


void parse(string str)
{
    str = str + "$";
    string stk = "$";

    int i = 0;
    while(true)
    {
        // cout<<stk<<endl;

        if(stk == "$E" && str[i] == '$') 
        {
            cout<<"SUCCESS"<<endl;
            return;
        }

        else if(i > str.length())
        {
            cout<<"FAILED"<<endl;
            return;
        }

        else
        {
            int j;
            string tmp = "";
            
            for(j = stk.length() - 1; j >= 0; j--)
            {
                tmp = tmp + stk[j];

                string tmp2 = reverse_str(tmp);

                if(productions[tmp2] != "")
                {
                    stk.erase(stk.length() - tmp.length());
                    stk = stk + productions[tmp2];
                    tmp = "";
                    break;
                }
            }

            if(j <= 0)
            {
                stk = stk + str[i];
                i += 1;
            } 
        }
    }

}


string reverse_str(string str)
{
    string res = "";

    for(int i = str.length() - 1; i >= 0; i--)
    {
        res = res + str[i];
    }

    return res;
}

