/*
 ID: dinovin1
 PROG: hamming
 LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int N, B, D;
vector<int> codewords;

int main()
{
    ifstream cin("hamming.in");
    ofstream cout("hamming.out");
    cin >> N >> B >> D;
    bool add = true;
    int count = N-1, difference = 0, numOnes = 0, number = 0;
    codewords.push_back(0);
    while (count) {
        add = true;
        for (int i=0; i<codewords.size(); i++) {
            difference = codewords[i]^number;
            for (; difference; numOnes++, difference &= (difference-1));
            if (numOnes<D) add = false;
            numOnes = 0;
        }
        if (add)
            codewords.push_back(number), count--;
        number++;
    }
    for (int i=0; i<codewords.size(); i++) {
        if ((i%10==9&&i) || i==codewords.size()-1)
            cout <<  codewords[i] << endl;
        else
            cout << codewords[i] << " ";
    }
    return 0;
}