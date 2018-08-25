/*
 ID: dinovin1
 PROG: maze1
 LANG: C++14
*/

//#include <iostream>
#include <fstream>
#include <queue>
#define MAX_W 38
#define MAX_H 100
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
char g[2*MAX_H+1][2*MAX_W+1];
int len[2*MAX_H+1][2*MAX_W+1];

struct node {
    int x, y;
    node(int x=0, int y=0) : x(x), y(y) {}
};

int main() {
    ifstream cin("maze1.in");
    ofstream cout("maze1.out");
    int W, H;
    cin >> W >> H;
    W *= 2, H *= 2;
    cin.get();
    for (int row=0; row<=H; ++row) {
        for (int col=0; col<=W; ++col)
            g[row][col] = cin.get();
        cin.get();
    }
    queue<node> q;
    for (int i=W-1; i>0; i-=2) {
        if (g[0][i] == ' ') {
            q.push(node(1, i));
            len[1][i] = 1;
        }
        if (g[H][i] == ' ') {
            q.push(node(H-1, i));
            len[H-1][i] = 1;
        }
    }
    for (int i=H-1; i>0; i-=2) {
        if (g[i][0] == ' ') {
            q.push(node(i, 1));
            len[i][1] = 1;
        }
        if (g[i][W] == ' ') {
            q.push(node(i, W-1));
            len[i][W-1] = 1;
        }
    }
    int ans = 1;
    while (!q.empty()) {
        node k = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = k.x + dx[i], y = k.y + dy[i];
            if (g[x][y] == ' ') {
                x += dx[i], y += dy[i];
                if (x > 0 && x < H && y > 0 && y < W && len[x][y] == 0) {
                    len[x][y] = len[k.x][k.y] + 1;
                    ans = max(ans, len[x][y]);
                    q.push(node(x, y));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
