/*
 ID: dinovin1
 PROG: lamps
 LANG: C++14
 */

#include <iostream>
#include <fstream>
#include <set>
using namespace std;
int N, C, lamps[100], sample[100];
set<int> solutions;

bool check(int lamps[], int sample[])
{
    for (int i=0; i<N; i++)
        if ((lamps[i]==1 && sample[i]==0)||(lamps[i]==0 && sample[i]==1))
            return false;
    return true;
}

void add(int sample[], set<int> &solutions) {
    int number = 0;
    for (int i=0; i<min(N,6); i++)
        number = (number << 1) + sample[i];
    solutions.insert(number);
}

string show_binary(int u, int num_of_bits)
{
    string a = "";
    for (int t = 1<<(min(N,6)-1); t; t/=2) {
        if (u >= t) {
            u -= t;
            a += "1";
        }
        else {
            a += "0";
        }
    }
    if(N>6)
        for(int j=0; j<(N-6); j++)
            a += a[j%6];
    return a;
}

void button(int applyToButton){
    switch (applyToButton) {
        case 0:
            for (int i = 0; i < N; i++) sample[i] = !sample[i];
            break;
        case 1:
            for (int i = 0; i < N; i += 2) sample[i] = !sample[i];
            break;
        case 2:
            for (int i = 1; i < N; i += 2) sample[i] = !sample[i];
            break;
        case 3:
            for (int i = 0; i < N; i += 3) sample[i] = !sample[i];
            break;
        default:
            break;
    }
}

int main()
{
    ifstream cin("lamps.in");
    ofstream cout("lamps.out");
    cin >> N >> C;
    for (int i=0; i<N; i++)
        lamps[i]=-1;
    for (int i=0; i<N; i++)
        sample[i]=1;
    while (true) {
        int number=0;
        cin >> number;
        if (number == -1)
            break;
        lamps[number-1]=1;
    }
    while (true) {
        int number=0;
        cin >> number;
        if (number == -1)
            break;
        lamps[number-1]=0;
    }
    if(C%2) {
        button(0);
        if (check(lamps, sample))
            add(sample, solutions);
        button(0), button(1);
        if (check(lamps, sample))
            add(sample, solutions);
        button(1), button(2);
        if (check(lamps, sample))
            add(sample, solutions);
        button(2), button(3);
        if (check(lamps, sample))
            add(sample, solutions);
        button(3);
        if(C>1) {
            button(0), button(1), button(2);
            if (check(lamps, sample))
                add(sample, solutions);
            button(2), button(3);
            if (check(lamps, sample))
                add(sample, solutions);
            button(1), button(2);
            if (check(lamps, sample))
                add(sample, solutions);
            button(0), button(1);
            if (check(lamps, sample))
                add(sample, solutions);
        }
    }
    else {
        if (check(lamps, sample))
            add(sample, solutions);
        if (C>0) {
            if (check(lamps, sample))
                add(sample, solutions);
            button(0), button(1);
            if (check(lamps, sample))
                add(sample, solutions);
            button(1), button(2);
            if (check(lamps, sample))
                add(sample, solutions);
            button(2), button(3);
            if (check(lamps, sample))
                add(sample, solutions);
            button(0), button(2);
            if (check(lamps, sample))
                add(sample, solutions);
            button(2), button(1);
            if (check(lamps, sample))
                add(sample, solutions);
            button(3), button(2);
            if (check(lamps, sample))
                add(sample, solutions);
            button(2), button(1);
            if(C>2) {
                button(0), button(1), button(2), button(3);
                if (check(lamps, sample))
                    add(sample, solutions);
            }
        }
    }
    if (solutions.size())
        for (int i: solutions)
            cout << show_binary(i, N) << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}