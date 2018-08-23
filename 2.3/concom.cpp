/*
 ID: dinovin1
 PROG: concom
 LANG: C++14
 */

#include <iostream>
#include <fstream>
#define NCOM 101
using namespace std;
const int maxn = 110;

int d[maxn][maxn], c[maxn];
bool vis[maxn];

void dfs(int u) {
    vis[u] = true;
    for (int i = 1; i < maxn; ++i) {
        c[i] += d[u][i];
        if (c[i] > 50 && !vis[i]) {
            dfs(i);
        }
    }
}

int main() {
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int u, v, x;
        scanf("%d%d%d", &u, &v, &x);
        d[u][v] = x;
    }
    for (int i = 1; i < maxn; ++i) {
        //memset(c, 0, sizeof c);
        //memset(vis, 0, sizeof vis);
        for (int z=0; z<110; z++)
            c[z]=vis[z]=0;
        dfs(i);
        for (int j = 1; j < maxn; ++j) {
            if (i != j && c[j] > 50) {
                printf("%d %d\n", i, j);
            }
        }
    }
    return 0;
}