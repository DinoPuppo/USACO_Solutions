/*
 ID: dinovin1
 PROG: skidesign
 LANG: C++
 */

#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream in("skidesign.in");
    ofstream out("skidesign.out");
    vector<int> hills;
    int total, current, result = 0, min_result = 5000000;
    in >> total;
    for(int i = 0; i < total; i++) {
        in >> current;
        hills.push_back(current);
    }
    for(int i = 1; i < 83; i++, result = 0) {
        for(int j = 0; j < total; j++) {
            if(hills[j] > i+17)
                result += (hills[j]-i-17)*(hills[j]-i-17);
            if(hills[j] < i)
                result += (hills[j]-i)*(hills[j]-i);
        }
        min_result = min(result, min_result);
    }
    out << min_result << endl;
}