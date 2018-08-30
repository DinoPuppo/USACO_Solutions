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

int A, B, C, a, b, c, prev_a, prev_b, prev_c;
vector<int> list = {0, 0, 0};
set<int> answer;

void pour(int &a, int &b, int cap)
{
    int prev = b;
    b = min(b+a, cap);
    a = max(a+prev-cap, 0);
}

bool find(int i, int a, int b , int c)
{
    for (int k=0; k<list.size(); k+=4)
        if (list[k]==i && list[k+1]==a && list[k+2]==b && list[k+3]==c) return true;
    return false;
}

void solve()
{
    for (int i=0; i<6; i++) {
        prev_a = a, prev_b = b, prev_c = c;
        if (a == 0)
            answer.insert(c);
        if (i==0) pour(a, b, B);
        if (i==1) pour(a, c, C);
        if (i==2) pour(b, a, A);
        if (i==3) pour(b, c, C);
        if (i==4) pour(c, a, A);
        if (i==5) pour(c, b, B);
        if (find(i, a, b, c))
            a = prev_a, b = prev_b, c = prev_c;
        else {
            list.push_back(i), list.push_back(a), list.push_back(b), list.push_back(c);
            solve();
        }
    }
    return;
}

int main()
{
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");
    fin >> A >> B >> C;
    a = b = 0, c = C;
    list.push_back(C);
    solve();
    bool no_space = true;
    for (auto item : answer) {
        fout << (no_space? "": " ") << item;
        no_space = false;
    }
    fout << endl;
    return 0;
}