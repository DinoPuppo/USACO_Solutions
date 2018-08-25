/*
 ID: dinovin1
 PROG: cowtour
 LANG: C++14
*/

#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin;
ofstream fout;

const int INFINITE = 100000*101;

int distance[101], intree[101], source[101];
int treesize = 0, treecost = 0;
int weight[101][101];

int main()
{
    fin.open("cowtour.in");
    fout.open("cowtour.out");
    
    int graphSize;
    fin >> graphSize;
    
    for (int i = 0; i < graphSize; i++) {
        distance[i]=INFINITE;
        intree[i]=0;
        source[i]=-1;
        for (int j = 0; i < graphSize; i++)
            fin >> weight[i][j];
    }
    
    treesize=1;
    for (int i=1; i<graphSize; i++)
        distance[i]=weight[1][i];
    while(treesize<graphSize)
        
    
    }
    for (int i = 0; i < n; ++i) {
        g[i][i] = 0;
    }
    
    // calculate shorest path
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][k] + g[j][k] < g[i][j]) {
                    g[i][j] = g[i][k] + g[j][k];
                }
            }
        }
    }
    
    for (int p = 0; p < n; ++p) {
        maxDistance[p] = 0;
    }
    
    for (int p = 0; p < n; ++p) {
        for (int src = 0; src < n; ++src) {
            if (g[p][src] != INFINITE && g[p][src] > maxDistance[p]) {
                maxDistance[p] = g[p][src];
            }
        }
    }
    
    for (int p1 = 0; p1 < n; p1++) {
        for (int p2 = 0; p2 < n; p2++) {
            // select two different area
            if (g[p1][p2] != INFINITE) {
                continue;
            }
            
            // get max distance in area1
            double max1 = maxDistance[p1];
            double max2 = maxDistance[p2];
            double distance = max1 + max2 + getDistance(p1, p2);
            
            //cout << char('A' + p1) << "-" << char('A' + p2) << " " << max1 << " " << max2 << " " << distance << endl;
            
            if (distance < ans) {
                ans = distance;
            }
        }
    }
    
    for (int p = 0; p < n; ++p) {
        if (maxDistance[p] > ans) {
            ans = maxDistance[p];
        }
    }
    
    fout.setf(ios::fixed);
    fout << setprecision(6) << ans << endl;
    
    return 0;
}

/*

#include <iostream>
#include <fstream>
#define INF 60000
using namespace std;

int path[151][151];
int x[151], y[151];
int N;

int main()
{
    ifstream cin("cowtour.in");
    ofstream cout("cowtour.out");
    
    cin >> N;
    
    for(int i=0; i<N; i++)
        cin >> x[i] >> y[i];
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            path[i][j] = cin.get();
        cin.get();
    }
    
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
}*/