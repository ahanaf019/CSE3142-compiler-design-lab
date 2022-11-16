#include<bits/stdc++.h>

using namespace std;

bool isNonTerminal(char c);

map<char, set<char>> first;
map<char, set<char>> follow;

struct prod{
    char left;
    string right;
    bool starting = false;
};

vector<prod> prods;
char calculateFirst(prod p, char N);
void calculateFollow(prod p);


int main()
{
    int n, m;
    cin>>n;
    char nonTerminals[n];

    for(int i = 0; i < n; i++)
        cin>>nonTerminals[i];
    
    cin>>m;
    char c;
    string x;
    for(int i = 0; i < m; i++)
    {
        prod p;
        cin>>c>>x;
        p.left = c;
        p.right = x;

        if(i == 0) p.starting = true;

        prods.push_back(p);
    }

    for(int i = 0; i < prods.size(); i++)
    {
        calculateFirst(prods[i], prods[i].left);
    }

    for(int i = 0; i < prods.size(); i++)
    {
        calculateFollow(prods[i]);
    }


    for(auto i: nonTerminals)
    {
        cout<<"First of "<<i<<": ";
        for(auto k: first[i])
            cout<<k<<" ";
        cout<<endl;
    }

        for(auto i: nonTerminals)
    {
        cout<<"Follow of "<<i<<": ";
        for(auto k: follow[i])
            cout<<k<<" ";
        cout<<endl;
    }


    return 0;
}

char calculateFirst(prod p, char N)
{
    if(!isNonTerminal(p.right[0]))
    {
        first[N].insert(p.right[0]);
        return p.right[0];
    }

    for(int i = 0; i < prods.size(); i++)
    {
        if(prods[i].left == p.right[0])
        {
            char c = calculateFirst(prods[i], N);

            if(c == '#')
            {
                first[N].erase('$');
                prod x = p;
                x.right = x.right.substr(1);
                
                if( x.right != "")
                    c = calculateFirst(x, N);

                else first[N].insert('$');
            }
        }
    }

    return 'A';
}


void calculateFollow(prod p)
{
    if(p.starting) follow[p.left].insert('$');

    for(int i = 0; i < prods.size(); i++)
    {
        string right = prods[i].right;
        for(int j = 0; right[j] != '\0'; j++)
        {
            if(p.left == right[j] && right[j+1] == '\0')
            {
                for(auto i: follow[prods[i].left])
                    follow[p.left].insert(i);
            }

            if(p.left == right[j] && right[j+1] != '\0')
            {
                if(isNonTerminal(right[j+1]))
                {
                    for(auto k: first[right[j+1]])
                    {
                        cout<<k<<endl;
                        if(k != '#')
                            follow[p.left].insert(k);
                            
                        else 
                        {
                            for(auto m: follow[prods[i].left])
                                follow[p.left].insert(m);
                        }
                    }
                }
                else follow[p.left].insert(right[j+1]); 
            }
        }
        
    }
}



bool isNonTerminal(char c)
{
    if(c >= 'A' && c <= 'Z') return true;
    return false;
}