/*
 ID: dinovin1
 PROG: fracdec
 LANG: C++14
 */

#include <iostream>
#include <fstream>
#include <cmath>
#define MAX 300000
using namespace std;

int decimal[MAX+1];

int gcd(int n,int m)
{
    return m==0? n: gcd(m,n%m);
}

int main()
{
    ifstream cin("fracdec.in");
    ofstream cout("fracdec.out");
    int N, D;
    cin >> N >> D;
    int prev_n = N;
    N /= gcd(N,D), D /= gcd(prev_n,D);
    int numerator = N;
    cout << numerator/D << ".";
    for (int i=0; i<=MAX; i++) {
        numerator = (numerator%D)*10;
        decimal[i] = numerator/D;
    }
    int highest2=0, highest5=0, new_denominator=D;
    while (new_denominator%2==0) {
        new_denominator /= 2;
        highest2++;
    }
    while (new_denominator%5==0) {
        new_denominator /= 5;
        highest5++;
    }
    for (int i=0; i<max(highest2, highest5); i++) {
        cout << decimal[i];
    }
    if (new_denominator==1) {
        if (max(highest2, highest5)==0) cout << 0;
        cout << endl;
        return 0;
    }
    cout << "(";
    int cnt=MAX-1;
    bool a = false;
    for (int j=1; j<=D-1; j++) {
        for (int i=max(highest2, highest5); i<=MAX; i+=j) {
            if (i+j<=MAX && decimal[i]==decimal[i+j]) {
                a=true;
            }
            if (i+j<=MAX && decimal[i]!=decimal[i+j]) {
                a=false;
                break;
            }
            if (i+j>=MAX-MAX%j&&a) cnt=min(cnt,j);
        }
    }
int t = N/D==0? 0: int(log10(N/D));
int nchars=max(highest2, highest5)+3+t;
for (int i=0; i<cnt; i++) {
    cout << decimal[max(highest2, highest5)+i];
    nchars++;
    if(nchars%76==0)
    cout << "\n";
    }
    cout << ")" << endl;
}