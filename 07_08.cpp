#include<bits/stdc++.h>

using namespace std;


void check(string str);
bool keyword(string str);
bool oprt(string str);
bool identifier(string str);
bool integer(string str);
bool floatNumber(string str);
bool character(string str);
bool String(string str);


int main()
{
    string str;

    while(true)
    {
        cin>>str;
        check(str);
    }



    return 0;
}

void check(string str)
{

    if(keyword(str))
        cout<<"Keyword"<<endl;
    else if(oprt(str))
        cout<<"";
    else if(identifier(str))
        cout<<"Identifier"<<endl;
    else if(integer(str))
        cout<<"Integer"<<endl;
    else if(floatNumber(str))
        cout<<"Float"<<endl;
    else if(character(str))
        cout<<"Character"<<endl;
    else if(String(str))
        cout<<"String"<<endl;
    else cout<<"INVALID"<<endl;





}

bool keyword(string str)
{
    string keywords[] = {"asm",	"double",	"new",	"switch",
                        "auto",	"else",	"operator",	"template",
                        "break",	"enum",	"private",	"this",
                        "case",	"extern",	"protected",	"throw",
                        "catch",	"float",	"public",	"try",
                        "char",	"for",	"register",	"typedef",
                        "class",	"friend",	"return",	"union",
                        "const",	"goto",	"short",	"unsigned",
                        "continue",	"if",	"signed",	"virtual",
                        "default",	"inline",	"sizeof",	"void",
                        "delete",	"int",	"static",	"volatile" ,
                        "do",	"long",	"struct",	"while"};


    for(int i = 0; i < 48; i++)
    {
        if(str == keywords[i]) return true;
    }

    return false;
}


bool oprt(string str)
{
    string arithmaticOprs[] = {"+", "-", "*", "/", "%"};
    string relationalOprs[] = {"&&", "||", "!"};
    string logicalOprs[] = {">", "<", "==", ">=", "<=", "!="};
    string incrDecrOprs[] = {"++", "--"};
    string assignmentOprs[] = {"=", "+=", "-=", "*=", "/=", "%="};
    string bitwiseOprs[] = {">>", "<<", "&", "|", "^", "~"};


    for(auto i: arithmaticOprs)
    {
        if(str == i)
        {
            cout<<"Arithmatic Operator"<<endl;
            return true;
        }
    }

    for(auto i: logicalOprs)
    {
        if(str == i)
        {
            cout<<"Logical Operator"<<endl;
            return true;
        }
    }

    for(auto i: relationalOprs)
    {
        if(str == i)
        {
            cout<<"Relational Operator"<<endl;
            return true;
        }
    }

    for(auto i: incrDecrOprs)
    {
        if(str == i)
        {
            cout<<"Increment Decrement Operator"<<endl;
            return true;
        }
    }

    for(auto i: assignmentOprs)
    {
        if(str == i)
        {
            cout<<"Assignment Operator"<<endl;
            return true;
        }
    }

    for(auto i: bitwiseOprs)
    {
        if(str == i)
        {
            cout<<"Bitwise Operator"<<endl;
            return true;
        }
    }

    return false;

}


bool identifier(string str)
{
    if(!((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z') || str[0] == '_'))
        return false;
    for(int i = 1; str[i] != '\0'; i++)
    {
        if(!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9') || str[i] == '_'))
            return false;
    
    }
    
    return true;
}

bool integer(string str)
{
    if(str.length() > 18) return false;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(!(str[i] >= '0' && str[i] <= '9'))
            return false;
    }

    return true;
}



bool floatNumber(string str)
{
    int count = 0;
    int pos = -1;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == '.') 
        {
            count += 1;
            pos = i;
        }
    }

    if(count != 1) return false;

    if(pos == 0) return false;

    if(pos == 1)
    {
        if(!(str[0] >= '0' && str[0] <= '9')) return false;
    }

    else 
    {
        if(!(str[0] >= '1' && str[0] <= '9')) return false;
        
        for(int i = 1; i < pos; i++)
        {
            if(!(str[i] >= '0' && str[i] <= '9')) return false;
        }
    }

    for(int i = pos + 1; str[i] != '\0'; i++)
    {
        if(!(str[i] >= '0' && str[i] <= '9')) return false;
    }

    return true;
}

bool character(string str)
{
    if(!(str.length() == 3 || str.length() == 4)) return false;

    if(!(str[0] == '\'' && str[str.length() - 1] == '\'')) return false;

    if(str.length() == 3) return true;

    if(str[1] == '\\')
    {
        // char x[] = {'\\', '\n', '\t', '\r', '\\', '\'', '\"'};

        // for(auto i: x)
        //     if(x == str[2]) return true;

        return true;
    }

    return false;
}

bool String(string str)
{
      if(!(str[0] == '\"' && str[str.length() - 1] == '\"')) return false;

        for(int i = 1; i < str.length() - 1; i++)
        {
            if(str[i] == '\"')
                if(str[i - 1] != '\\') return false; 
        }

        return true;
}

