/*
 ID: tausiq11
 PROG: crypt1
 LANG: C++
 */

#include <fstream>
using namespace std;

int a [10];
int n;
int count;

bool find (int x) {
    for (int i = 0; i < n; i++)
        if (a[i] == x) return true;
    return false;
}

void function (int p, int q, int r, int s, int t) {
    int first = p*100 + q*10 + r;
    int second = s*10 + t;
    if (first*second > 9999) return;
    int temp = first * t;
    if (temp > 999) return;
    while (temp) {
        if (!find(temp%10)) return;
        temp /= 10;
    }
    temp = first * s;
    if (temp > 999)
        return;
    while (temp) {
        if (!find(temp%10)) return;
        temp /= 10;
    }
    temp = first * second;
    while (temp) {
        if (!find(temp%10)) return;
        temp /= 10;
    }
    count++;
}

int main () {
    ifstream in("crypt1.in");
    ofstream out("crypt1.out");
    in >> n;
    count = 0;
    for (int i = 0; i < n; i++) in >> a[i];
    if (n < 5) {
        out << count << endl;
        return 0;
    }
    for (int p = 0; p < n; p++)
        for (int q = 0; q < n; q++)
            for (int r = 0; r < n; r++)
                for (int s = 0; s < n; s++)
                    for (int t = 0; t < n; t++)
                        function (a[p], a[q], a[r], a[s], a[t]);
    out << count << endl;
    return 0;
}

