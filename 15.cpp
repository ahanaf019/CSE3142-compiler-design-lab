#include<bits/stdc++.h>

using namespace std;


map<pair<char, char>, string> productions;
vector<pair<pair<char,string>, int>> parse_tree;


void solve(string str);
bool parse(string str);

int main()
{
    string str = "id+id*id";

    productions[make_pair('E', 'X')] = "TP";
    productions[make_pair('E', '(')] = "TP";
    productions[make_pair('P', '+')] = "+TP";
    productions[make_pair('P', ')')] = "@";
    productions[make_pair('P', '$')] = "@";
    productions[make_pair('T', 'X')] = "FQ";
    productions[make_pair('T', '(')] = "FQ";
    productions[make_pair('Q', '+')] = "@";
    productions[make_pair('Q', ')')] = "@";
    productions[make_pair('Q', '$')] = "@";
    productions[make_pair('Q', '*')] = "*FQ";
    productions[make_pair('F', 'X')] = "X";
    productions[make_pair('F', '(')] = "(E)";


    solve(str);

    return 0;
}


void solve(string str)
{

    string temp = "";
    string final = "";

    for(int i = 0; str[i] != '\0'; i++)
    {
        temp = temp + str[i];

        if(temp == "i")
            continue;

        else if(temp == "id")
        {
            final = final + "X";
            temp = "";
        }

        else   
        {
            final = final + temp;
            temp = "";
        
        }
    }

    // cout<<final<<endl;
    cout<<str<<endl<<endl;

    if(parse(final))
    {
        for(auto x: parse_tree)
        {
            int lvl = x.second;
            char c = x.first.first;
            string s = x.first.second;

            for(int k = 0; k < lvl; k++)
                    cout<<"      ";
        
            cout<<c<<" --> "<<s<<endl;
        }
    }

}


bool parse(string str)
{
    stack<pair<char, int>> stk;
    stk.push({'$', 0});
    stk.push({'E', 0});

    str = str + "$";

    int i = 0;
    // int level = 0;

    while(true)
    {
        char top = stk.top().first;
        int lvl = stk.top().second;
        // cout<<(char)top<<endl;
        if(top == str[i])
        {
            if(top == '$')
            {
                cout<<"SUCCESS"<<endl;
                return true;
            }

            else if(top != 'E' && top != 'T' && top != 'F' && top != 'P' && top != 'Q')
            {
                i += 1;
                stk.pop();
            }
        }

        else
        {
            if( productions[make_pair(top, str[i])] == "" )
            {
                cout<<"FAILED"<<endl;
                return false;
            }

            string prod = productions[make_pair(top, str[i])];


            // for(int k = 0; k < lvl; k++)
            //     cout<<"      ";

            parse_tree.push_back({{char(top), (prod == "X" ? "id" : prod)}, lvl});

            // cout<<char(top)<<" --> "<<(prod == "X" ? "id" : prod)<<endl;

            if(prod == "@") prod = "";
            

            // cout<<(char)top<<" "<<prod<<" "<<str[i]<<endl;
            stk.pop();

            for(int j = prod.length() - 1; j >= 0; j--)
            {
                stk.push({prod[j], lvl + 1});
            }
        }
    }

    return false;
}