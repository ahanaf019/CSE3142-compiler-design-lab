#include<bits/stdc++.h>

using namespace std;


int main()
{
    string str = "CSE-3142";

    string cse = "Computer Science & Engineering";

    string years[] = {"1st", "2nd", "3rd", "4th"};
    string semesters[] = {"1st", "2nd"};
    string courses[] = {"System Analysis and Design", "Digital Signal Processing", "Database Management System", "Compiler Design", "Computer Networks"};
    string type[] = {"Theory", "Lab"};

    if(str[0] == 'C' && str[1] == 'S' && str[2] == 'E')
    {
        cout<<cse<<", ";
        
        cout<<years[int(str[4] - '0') - 1]<<" year, ";
        cout<<semesters[int(str[5] - '0') - 1]<<" semester, ";
        cout<<courses[int(str[6] - '0') - 1]<<", ";
        cout<<type[int(str[7] - '0') - 1]<<endl;



    }



    return 0;
}