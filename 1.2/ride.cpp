/*
 ID: dinovin1
 PROG: ride
 LANG: C++                
 */

#include <fstream>
using namespace std;

int f(string s) {
    return (s.size() ? (s[0] - 64) * f(s.substr(1)) : 1) % 47;
}

int main()
{
    ifstream in("ride.in");
    ofstream out("ride.out");
    string a, b;
    in >> a >> b;
    out << (f(a) == f(b) ? "GO\n" : "STAY\n");
}