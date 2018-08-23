/*
 ID: dinovin1
 PROG: preface
 LANG: C++14
 */

#include <iostream>
#include <fstream>
using namespace std;
int i[3500], v[3500], x[3500], l[3500], c[3500], d[3500], m[3500];

int main()
{
    ifstream cin("preface.in");
    ofstream cout("preface.out");
    int N;
    cin >> N;
    for (int j=1; j<3500; j++) {
        i[j] = i[j-1] + j%5-(j%5)/4*3;
        v[j] = v[j-1] + (j%10+2)/6*2-(j%10+1)/5;
        x[j] = x[j-1] + (j/10)%5-((j/10)%5)/4*3+(j%10/9);
        l[j] = l[j-1] + ((j/10)%10+2)/6*2-((j/10)%10+1)/5;
        c[j] = c[j-1] + (j/100)%5-((j/100)%5)/4*3+(j%100/90);
        d[j] = d[j-1] + ((j/100)%10+2)/6*2-((j/100)%10+1)/5;
        m[j] = m[j-1] + (j/1000)%5-((j/1000)%5)/4*3+(j%1000/900);
    }
    cout << "I " << i[N] << endl;
    if (N>3)
        cout << "V " << v[N] << endl;
    if (N>8)
        cout << "X " << x[N] << endl;
    if (N>39)
        cout << "L " << l[N] << endl;
    if (N>89)
        cout << "C " << c[N] << endl;
    if (N>399)
        cout << "D " << d[N] << endl;
    if (N>899)
        cout << "M " << m[N] << endl;
    return 0;
}