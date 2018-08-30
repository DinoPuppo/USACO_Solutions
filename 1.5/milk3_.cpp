/*
 ID: dinovin1
 PROG: milk3
 LANG: C++14
 */

#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int A, B, C, a, b, c, prev_a, prev_b, prev_c, previous_a, previous_b, previous_c;
vector<int> list = {0, 1, 0, 0};
set<int> answer;

void pour(int from, int to)
{
    if (from == 0) {
        if (to == 1) {
            prev_b = b;
            b = min(b+a, B);
            a = max(a+prev_b-B, 0);
        }
        if (to == 2) {
            prev_c = c;
            c = min(c+a, C);
            a = max(a+prev_c-C, 0);
        }
    }
    if (from == 1) {
        if (to == 0) {
            prev_a = a;
            a = min(a+b, A);
            b = max(b+prev_a-A, 0);
        }
        if (to == 2) {
            prev_c = c;
            c = min(c+b, C);
            b = max(b+prev_c-C, 0);
        }
    }
    if (from == 2) {
        if (to == 0) {
            prev_a = a;
            a = min(a+c, A);
            c = max(c+prev_a-A, 0);
        }
        if (to == 1) {
            prev_b = b;
            b = min(b+c, B);
            c = max(c+prev_b-B, 0);
        }
    }
}

bool find(int i, int j, int a, int b , int c)
{
    for (int k=0; k<list.size(); k+=5)
        if (list[k]==i && list[k+1]==j && list[k+2]==a && list[k+3]==b && list[k+4]==c) return true;
    return false;
}

void solve()
{
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++) {
            if (j!=i) {
                previous_a = a;
                previous_b = b;
                previous_c = c;
                pour(i, j);
                if (find(i, j, a, b, c)) {
                    a = previous_a;
                    b = previous_b;
                    c = previous_c;
                }
                else {
                    list.push_back(i);
                    list.push_back(j);
                    list.push_back(a);
                    list.push_back(b);
                    list.push_back(c);
                    solve();
                }
            }
        }
    return;
}

int main()
{
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");
    fin >> A >> B >> C;
    a = b = 0;
    c = C;
    list.push_back(C);
    solve();
    for (int i=0; i<list.size(); i+=5)
        if (list[i+2]==0) answer.insert(list[i+4]);
    bool no_space = true;
    for (auto item : answer) {
        fout << (no_space? "": " ") << item;
        no_space = false;
    }
    fout << endl;
    return 0;
}