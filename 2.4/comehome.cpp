/*
 ID: dinovin1
 PROG: comehome
 LANG: C++14
*/

#include <iostream>
#include <fstream>
#define INF 60000
using namespace std;

int dist[52][52];

int char2num(char c)
{
    return isupper(c)? c-'A': c-'a'+26;
}

int main()
{
    int i, j, k, P, c;
    char a, b;
    int m;
    ifstream cin("comehome.in");
    ofstream cout("comehome.out");
    
    for(i=0; i<52; i++)
        for(j=0; j<52; j++)
            dist[i][j] = INF;
    
    for(i=0; i<26; i++)
        dist[i][i] = 0;
    
    cin >> P;
    for (int i=0; i<P; i++) {
        cin >> a >> b >> c;
        a = char2num(a);
        b = char2num(b);
        if(dist[a][b] > c)
            dist[a][b] = dist[b][a] = c;
    }
    
    for(k=0; k<52; k++)
        for(i=0; i<52; i++)
            for(j=0; j<52; j++)
                if(dist[i][k]+dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k]+dist[k][j];
    
    m = INF;
    a = '#';
    for(i='A'; i<='Y'; i++) {
        c = dist[char2num(i)][char2num('Z')];
        if(c < m) {
            m = c;
            a = i;
        }
    }
    cout << a << " " << m << endl;
}