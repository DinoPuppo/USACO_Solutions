/*
 ID: dinovin1
 PROG: milk
 LANG: C++
 */

#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

void sort(vector<int> &to_sort, vector<int> &other) {
    int n = int(to_sort.size());
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < n-1; y++) {
            if(to_sort[y] > to_sort[y+1]) {
                int temp = to_sort[y+1];
                to_sort[y+1] = to_sort[y];
                to_sort[y] = temp;
                int temp_ = other[y+1];
                other[y+1] = other[y];
                other[y] = temp_;
            }
        }
    }
}

int main() {
    ifstream in("milk.in");
    ofstream out("milk.out");
    vector<int> price, amount;
    int total, n, count = 0, result = 0, j = 0, a, b;
    in >> total >> n;
    for(int i = 0; i < n; i++) {
        in >> a >> b;
        price.push_back(a);
        amount.push_back(b);
    }
    sort(price, amount);
    while (n != 0) {
        if (count + amount[j] > total) {
            result += (total - count)*price[j];
            break;
        }
        else {
            result += amount[j]*price[j];
            count += amount[j];
        }
        j++;
    }
    out << result << endl;
}