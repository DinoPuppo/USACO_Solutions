/*
 ID: dinovin1
 PROG: runround
 LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

bool runround(int num)
{
    string numstr = to_string(num);
    int i=0, c=1;
    int mark[255] = {0};
    mark[numstr[0]] = true;
    
    while (true){
        i = (i+numstr[i]-'0')%numstr.length();
        if(mark[numstr[i]] == true)
            return i == 0 && c == numstr.length();
        else
            mark[numstr[i]] = true, c++;
    }
}

int main()
{
    ifstream cin("runround.in");
    ofstream cout("runround.out");
    int N;
    cin >> N;
    N++;
    while (!runround(N)) N++;
    cout << N << endl;
    return 0;
}