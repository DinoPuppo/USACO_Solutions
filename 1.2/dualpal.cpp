/*
 ID: dinovin1
 PROG: dualpal
 LANG: C++
 */

#include <fstream>
using namespace std;

string reverse(string str)
{
    for (int i=0; i<str.length()/2; i++)
        swap(str[i], str[str.length()-i-1]);
    return str;
}

string change_base(int num, int base) {
    string result = "";
    while (num > 0) {
        result = char(48 + num%base + (num%base/10)*7) + result;
        num = (num - num%base)/base;
    }
    return result;
}

int main() {
    ifstream in("dualpal.in");
    ofstream out("dualpal.out");
    int N, S, pal_count = 0, count = 0;
    in >> N >> S;
    int z = S + 1;
    while(pal_count < N) {
        for (int base = 2; base < 11; base++)
            if (change_base(z, base) == reverse(change_base(z, base))) count++;
        if (count >= 2) {
            out << z << endl;
            pal_count++;
        }
        count = 0;
        z++;
    }
}

