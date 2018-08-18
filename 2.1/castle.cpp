/*
 ID: dinovin1
 PROG: castle
 LANG: C++
 */

//#include <iostream>
#include <fstream>
using namespace std;

int r, c, rn, maxn, max2n, wx, wy, wd;
int m[55][55], v[55][55], b[55][55], room[3000];

void dfs(int i, int j, int& s)
{
    if (v[i][j]) return;
    v[i][j] = 1;
    b[i][j] = rn;
    s++;
    if (!(m[i][j]&1)) dfs(i, j-1, s);
    if (!(m[i][j]&2)) dfs(i-1, j, s);
    if (!(m[i][j]&4)) dfs(i, j+1, s);
    if (!(m[i][j]&8)) dfs(i+1, j, s);
}

int main()
{
    ifstream cin("castle.in");
    ofstream cout("castle.out");
    cin >> c >> r;
    for (int i=1; i<=r; i++)
        for (int j=1; j<=c; j++)
            cin >> m[i][j];
    for (int i=1; i<=r; i++)
        for (int j=1; j<=c; j++)
            if(!v[i][j])
            {
                rn++;
                int tn = 0;
                dfs(i, j, tn);
                room[rn] = tn;
                maxn = max(maxn, tn);
            }
    for (int j=1; j<=c; j++)
        for (int i=r; i>=1; i--)
        {
            if (m[i][j]&2 && b[i-1][j] && b[i-1][j]!=b[i][j])
                if (room[b[i-1][j]] + room[b[i][j]] > max2n)
                {
                    max2n = room[b[i-1][j]] + room[b[i][j]];
                    wx = i, wy = j, wd = 'N';
                }
            if (m[i][j]&4 && b[i][j+1] && b[i][j+1]!=b[i][j])
                if (room[b[i][j+1]] + room[b[i][j]] > max2n)
                {
                    max2n = room[b[i][j+1]] + room[b[i][j]];
                    wx = i, wy = j, wd = 'E';
                }
        }   
    cout << rn << endl << maxn << endl << max2n << endl;
    cout << wx << " " << wy << " " << char(wd) <<endl;
    return 0;
}