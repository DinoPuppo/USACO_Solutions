/*
 ID: dinovin1
 PROG: barn1
 LANG: C++14
 */

#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ifstream in("barn1.in");
    ofstream out("barn1.out");
    vector<int> stalls, taken;
    int M, S, C, stall, max_difference = 0, flag = 0, difference = 0;
    in >> M >> S >> C;
    for(int i = 0; i < C; i++) {
        in >> stall;
        stalls.push_back(stall);
    }
    sort(stalls.begin(), stalls.end());
    int result = stalls[C-1] - stalls[0] + 1;
    while (M-1>0) {
        for(int i = 0; i < C; i++) {
            difference = find(taken.begin(), taken.end(), i)!=taken.end()? 0: stalls[i+1] - stalls[i] - 1;
            if (difference > max_difference) {
                max_difference = difference;
                flag = i;
            }
        }
        taken.push_back(flag);
        result = result - max_difference;
        max_difference = 0;
        M--;
    }
    out << result << endl;
}