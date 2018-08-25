/*
 ID: dinovin1
 PROG: comehome
 LANG: C++14
*/

#include <iostream>
#include <fstream>
#define MAX_PATHS 10000
#define MAX_DISTANCE ('z'-'a'+100)*1000
using namespace std;

int path[60][60], shortest[60], length;

void dfs(int previous)
{
    for (int i=0; i<='z'-'A'; i++) {
        if (i<'Z'-'A' && path[previous][i]) {
            shortest[i] = min(shortest[i], length+path[previous][i]);
        }
        if (i>='a'-'A' && path[previous][i]) {
            length += path[previous][i];
            dfs(i);
            //dfs(i);
        }
        path[previous][i] = path[i][previous] = 0;
    }
}

int main()
{
    ifstream cin("comehome.in");
    ofstream cout("comehome.out");
    for (int i=0; i<60; i++)
        shortest[i] = MAX_DISTANCE;
    int P;
    cin >> P;
    for (int i=0; i<P; i++) {
        char a='A', b='A';
        int c=0;
        cin >> a >> b >> c;
        if (a!=b) //????????????????????
            path[a-'A'][b-'A'] = path[b-'A'][a-'A'] = c;
    }
    dfs('Z'-'A');
    int answer = MAX_DISTANCE;
    char ans;
    for (int i=0; i<'Z'-'A'; i++)
        if (shortest[i]<answer) answer=shortest[i], ans=char(i+'A');
    cout << ans << " " << answer << endl;
}