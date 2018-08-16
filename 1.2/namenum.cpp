/*
 ID: dinovin1
 PROG: namenum
 LANG: C++
 */

#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
ifstream dict ("dict.txt");
ofstream fout ("namenum.out");
ifstream fin ("namenum.in");
vector<string> names;
vector<string> encodedNames;
string code;
bool found = false;

string encodeName(string name)
{
    string a = "";
    for(int i = 0; i < name.size(); ++i)
    {
        int current = (name[i] - 'A');
        if(current >= 16) --current;
        current /= 3;
        current += 2;
        a.push_back(current + '0');
    }
    return a;
}
int main()
{
    ios::sync_with_stdio(false);
    fin >> code;
    while(true)
    {
        string current;
        dict >> current;
        if(dict.eof()) break;
        names.push_back(current);
        encodedNames.push_back(encodeName(current));
    }
    bool found = false;
    for(int i = 0; i < encodedNames.size(); ++i)
    {
        if(encodedNames[i] == code)
        {
            fout<<names[i]<<"\n";
            found = true;
        }
    }
    if(!found) fout<<"NONE\n";
    return 0;
}
