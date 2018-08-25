/*
 ID: dinovin1
 PROG: ttwo
 LANG: C++14
*/

//#include <iostream>
#include <fstream>
#define SIZE 11
using namespace std;

int t, grid[SIZE+1][SIZE+1];

int main() {
    ifstream cin("ttwo.in");
    ofstream cout("ttwo.out");
    char input;
    int f_initial_i=0, f_initial_j=0, c_initial_i=0, c_initial_j=0, c_direction=0, f_direction=0;
    for (int i=0; i<=SIZE; i++)
        for (int j=0; j<=SIZE; j++) {
            if (i%SIZE==0||j%SIZE==0)
                grid[i][j]=-1;
            else {
                cin >> input;
                if (input=='*')
                    grid[i][j]=-1;
                if (input=='F')
                    f_initial_i=i, f_initial_j=j;
                if (input=='C')
                    c_initial_i=i, c_initial_j=j;
            }
        }
    int i=c_initial_i, j=c_initial_j, k=f_initial_i, l=f_initial_j;
    while (t<4*SIZE*SIZE&&!(i==k&&j==l)) {
        if (grid[i-!c_direction+!(c_direction-2)][j+!(c_direction-1)-!(c_direction-3)]==-1)
            c_direction = (c_direction+1)%4;
        else {
            i += -!c_direction+!(c_direction-2);
            j += !(c_direction-1)-!(c_direction-3);
        }
        if (grid[k-!f_direction+!(f_direction-2)][l+!(f_direction-1)-!(f_direction-3)]==-1)
            f_direction = (f_direction+1)%4;
        else {
            k += -!f_direction+!(f_direction-2);
            l += !(f_direction-1)-!(f_direction-3);
        }
        t++;
    }
    cout << t%(4*SIZE*SIZE) << endl;
    return 0;
}