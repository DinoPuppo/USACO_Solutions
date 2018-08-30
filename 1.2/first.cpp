/*
ID: dinovin1
PROG: test
LANG: C++
*/

#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream in("test.in");
    ofstream out("test.out");
    int a, b;
    in >> a >> b;
    out << a + b << endl;
    return 0;
}