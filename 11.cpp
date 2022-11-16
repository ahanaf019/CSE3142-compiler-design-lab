#include<bits/stdc++.h>

using namespace std;

bool solve(string str);
string reverse_str(string str);

map<string, string> prods;

vector<pair<string, string>> tree;


int main()
{
    string str = "(a+b)+c*a/(b-c)";
    // cout<<str.erase(str.length() - 2);

    prods["a"] = "E";
    prods["b"] = "E";
    prods["c"] = "E";
    prods["E+E"] = "E";
    prods["E-E"] = "E";
    prods["E*E"] = "E";
    prods["E/E"] = "E";
    prods["(E)"] = "E";

    // cout<<prods["xs"];
    if(solve(str))
    {
        string x = "E";
        cout<<"E"<<endl;
        for(int i = tree.size() - 1; i >=0; i--)
        {
            // cout<<tree[i].first<<"-->"<<tree[i].second<<endl;
            for(int j = x.length() - 1; j >= 0; j--)
            {
                if(x[j] == 'E')
                {
                    x.erase(j,1);
                    x.insert(j, tree[i].second);
                    break;
                }
            }
            cout<<x<<endl;
        }

    }
    


    




    return 0;
}


bool solve(string str)
{
    string stk = "$";
    str = str + "$";

    int i = 0;
    while(true)
    {
        // cout<<stk<<"\t\t";

        // for(int k = i; str[k] != '\0'; k++)
        //     cout<<str[k];
        // cout<<"\t\t";


        if(stk == "$E" && str[i] == '$')
        {
            cout<<"SUCCESS"<<endl;
            return true;
        }

        if(i > str.length() - 1)
        {
            cout<<"FAILED"<<endl;
            return false;
        }

        else
        {
            string tmp = "";
            int j;
            for(j = stk.length() - 1; j > 0; j--)
            {
                tmp = tmp + stk[j];

                string tmp2 = reverse_str(tmp);
                if(prods[tmp2] != "")
                {
                    stk.erase(stk.length() - tmp2.length());
                    stk = stk + prods[tmp2];
                    tmp = "";
                    // cout<<"REDUCE TO "<<prods[tmp2]<<" --> "<<tmp2<<endl;
                    tree.push_back({prods[tmp2], tmp2});
                    break;
                }
            }

            if(j <= 0)
            {
                // cout<<"SHIFT"<<endl;
                stk = stk + str[i];
                i = i+1;
            }
        }

    }
    return false;

}


string reverse_str(string str)
{
    string tmp = "";
    for(int i = str.length() - 1; i >=0; i--)
    {
        tmp = tmp + str[i];
    }
    return tmp;
}
