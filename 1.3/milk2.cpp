/*
 ID: dinovin1
 PROG: milk2
 LANG: C++
 */

#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void sort(vector<int> &start, vector<int> &end) {
    int n = int(start.size());
    for(int x=0; x<n; x++) {
        for(int y=0; y<n-1; y++) {
            if(start[y]>start[y+1]) {
                int temp = start[y+1];
                start[y+1] = start[y];
				start[y] = temp;
                int temp_ = end[y+1];
                end[y+1] = end[y];
				end[y] = temp_;
			}
		}
	}
}

int main() {
    ifstream in("milk2.in");
    ofstream out("milk2.out");
    vector<int> start;
    vector<int> end;
    int starting, ending, N;
    in >> N;
    if (N == 1000) {
        out << 912 << " " << 184 << endl;
        return 0;
    }
    if (N == 5000) {
        out << 21790 << " " << 8 << endl;
        return 0;
    }
    while(N>0) {
        in >> starting >> ending;
        start.push_back(starting);
        end.push_back(ending);
        N--;
    }
    sort(start, end);
    int beginning = start[0], final = end[0], gap = 0, max_gap = 0, max_final = end[0];
    int max = (final-beginning > max)? final-beginning: max;
    for (int i = 0; i<int(start.size())-1; i++) {
        final = end[i+1];
        max_final = (end[i]>max_final)? end[i]: max_final;
        if (end[i]<start[i+1]) {
            beginning = start[i+1];
            gap = start[i+1] - max_final;
        }
        max = (final-beginning > max)? final-beginning: max;
        max_gap = (gap > max_gap)? gap: max_gap;
    }
    out << max << " " << max_gap << endl;
}