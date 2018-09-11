/*
ID: dinovin1
PROG: fence9
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <fstream>
using namespace std;
 
int main()
{
    ifstream cin("fence9.in");
    ofstream cout("fence9.out");
    int n, m, p;
    cin >> n >> m >> p;
    int xRight = p;
    int xLeft = 0;
    int count = 0;
    int y=1;
    while (true)
    {
        while(xLeft<=y*n/m)
        {
            xLeft++;
        }
        while(xRight>=y*(n-p)/m+p)
        {
            xRight--;
        }
        if(xLeft>xRight)
            break;
        count += xRight-xLeft+1;
        y++;
    }
    cout << count << endl;
    return 0;
}
