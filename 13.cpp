#include<bits/stdc++.h>

using namespace std;


struct production {
    char left;
    string right;
    bool isStartingSymbol = false;
};

bool isNonTerminal(char c);
char calculateFirst(production prod, int index, char nt);
char calculateFollow(production prod, int index, char nt);


vector<production> prods;
map<char, set<char>> first;
map<char, set<char>> follow;
int len = 8;

int main()
{

    for(int i = 0; i < len; i++)
    {
        production x;
        char c;
        string s;
        if(i == 0) x.isStartingSymbol = true;
        cin>>c>>s;
        x.left = c;
        x.right = s;

        prods.push_back(x);
    }

    for(int i = len - 1; i >= 0; i--)
    {
        calculateFirst(prods[i], i, prods[i].left);
    }

    for(int i = 0; i < len; i++)
    {
        calculateFollow(prods[i], i, prods[i].left);
    }
    cout<<prods[0].isStartingSymbol<<endl;

    char terminals[] = {'E', 'Q', 'T', 'R', 'F'};

    for(auto i: terminals)
    {
        cout<<"First of "<<i<<":"<<endl;

        for(auto j: first[i])
        {
            cout<<j<<' ';
        }
        cout<<endl;
    }

    for(auto i: terminals)
    {
        cout<<"Follow of "<<i<<":"<<endl;

        for(auto j: follow[i])
        {
            cout<<j<<' ';
        }
        cout<<endl;
    }

    return 0;
}


char calculateFirst(production prod, int index, char nt)
{
    
    if(!isNonTerminal(prod.right[0])) 
    {
        first[nt].insert(prod.right[0]);
        return prod.right[0]; 
    }

    for(int i = 0; i < len; i++)
    {
        if(prods[i].left == prod.right[0])
        {
            production x = prod;
            char c = calculateFirst(prods[i], i, nt);

            if(c == '#')
            {
                first[nt].erase('#');
                x.right = x.right.substr(1);
                // cout<<(x.right == "")<<endl;
                if(x.right != "")
                {
                    c = calculateFirst(x, i, nt);
                }
                else 
                {
                    first[nt].insert('#');
                }
            }
        }
    }
    return 'A';
}


char calculateFollow(production prod, int index, char nt)
{
    // cout<<prod.left<<endl;
    if(prod.isStartingSymbol) follow[nt].insert('$');

    for(auto it: prods)
    {
        for(int i = 0; it.right[i] != '\0'; i++)
        {
            if(it.right[i] == nt && it.right[i + 1] == '\0')
            {
                for(auto x: follow[it.left])
                follow[nt].insert(x);
            }

            else if(it.right[i] == nt && it.right[i + 1] != '\0')
            {
                // cout<<it.left<<" "<<it.right<<" "<<nt<<endl;

                bool epsilon = false;

                if(!isNonTerminal(it.right[i+1])) follow[nt].insert(it.right[i+1]);

                for(auto x: first[it.right[i+1]])
                {
                    follow[nt].insert(x);

                    if(x == '#')
                    {
                        epsilon = true;
                        follow[nt].erase('#');
                    }

                }

                if(epsilon)
                {
                    if(!isNonTerminal(it.right[i + 1])) follow[nt].insert(it.right[i + 1]);

                    else
                    for(auto x: follow[it.right[i+1]])
                        follow[nt].insert(x);

                }
            }

        }
    }
    return 'a';
}


bool isNonTerminal(char c) 
{
    if(c >= 'A' && c <= 'Z') return true;

    return false;
}

