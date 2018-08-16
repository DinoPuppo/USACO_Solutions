/*
 ID: dinovin1
 PROG: namenum
 LANG: C++
 */

#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ifstream in("namenum.in");
    ifstream dict("dict.txt");
    ofstream out("namenum.out");
    string n, NAMES[5000], names[5000];
    in >> n;
    for(int i = 0; i < 5000; i++) dict >> NAMES[i];
    for(int i = 0; i < 5000; i++)
        for(int j = 0; j < NAMES[i].length(); j++)
            names[i][j] += (int(n[0])-int(n[0])/81-59)/3;
    for(int i = 0; i < 5000; i++)
        if(n==names[i]) out << NAMES[i] << endl;
}