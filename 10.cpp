#include<bits/stdc++.h>

using namespace std;

void parse(string str);
string reverse_str(string str);


map<string, string>prods;


int main()
{
    string str = "((x+x)*(x-x))/";
    
    prods["E+E"] = "E";
    prods["E-E"] = "E";
    prods["E*E"] = "E";
    prods["E/E"] = "E";
    prods["(E)"] = "E";
    prods["x"] = "E";
    cout<<str<<endl;
    parse(str);

    return 0;
}


void parse(string str)
{
    cout<<"STACK\t\tINPUT\t\tACTION"<<endl;
    cout<<"************************************"<<endl;
    str = str + "$";

    string stk = "$";

    int i = 0;
    while(true)
    {
        cout<<stk<<"\t\t";
        
        for(int k = i; str[k]!= '\0'; k++)
            cout<<str[k];
        cout<<"\t\t";

        if(str[i] == '$' && stk == "$E")
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
                    cout<<"REDUCE "<<prods[tmp2]<<" --> "<<tmp2<<endl;
                    break;
                }
            }

            if(j == 0)
            {
                cout<<"SHIFT "<<str[i]<<endl;
                stk = stk + str[i];
                i+= 1;
            }


        }


    }


}

string reverse_str(string str)
{
    string res = "";
    for(int i = str.length() - 1; i >= 0; i--)
    {
        res = res  + str[i];
    }
    return res;
}


