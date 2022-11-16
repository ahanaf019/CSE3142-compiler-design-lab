#include<bits/stdc++.h>

using namespace std;

map<pair<char, char>, string> prods;

void solve(string str);

int main()
{
    string str = "(x+x)*(x*(x))";

    prods[{'E', 'x'}] = "TQ";
    prods[{'E', '('}] = "TQ";
    prods[{'Q', '+'}] = "+TQ";
    prods[{'Q', ')'}] = "#";
    prods[{'Q', '$'}] = "#";
    prods[{'T', 'x'}] = "FR";
    prods[{'T', '('}] = "FR";
    prods[{'R', '+'}] = "#";
    prods[{'R', ')'}] = "#";
    prods[{'R', '$'}] = "#";
    prods[{'R', '*'}] = "*FR";
    prods[{'F', 'x'}] = "x";
    prods[{'F', '('}] = "(E)";


    cout<<str<<endl;
    solve(str);



    return 0;
}

void solve(string str)
{
    str = str + '$';
    stack<pair<char, int>> stk;
    stk.push({'$', 0});
    stk.push({'E', 0});


    int i = 0;
    while(true)
    {
        char top = stk.top().first;
        int level = stk.top().second;

        if(top == '$' && str[i] == '$')
        {
            cout<<"SUCCESS"<<endl;
            break;

        }

        if(top == str[i] && top != '$')
        {
            stk.pop();
            i = i+1;
        }

        else
        {
            if(prods[{top, str[i]}] != "")
            {
                string tmp = prods[{top, str[i]}];

                stk.pop();
                int lv = level;
                while (lv--)
                {
                    cout<<"    ";
                }
                

                cout<<top<<"-->"<<tmp<<endl;

                if(tmp != "#")
                {
                    for(int j = tmp.length() - 1; j >=0; j--)
                    {
                        stk.push({tmp[j], level + 1});
                    }
                }
            }
        }



    }

}
