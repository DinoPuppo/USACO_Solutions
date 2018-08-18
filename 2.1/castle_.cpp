/*
 ID: dinovin1
 PROG: castle
 LANG: C++14
 */

#include <fstream>
#include <iostream>
#include <set>
#include <map>
using namespace std;

int static castle[51*51+1][51*51+1];
int room[50*50+1], M, N, maximum, max_size;
map<int, set<int>> rooms;
/*
void flood_fill(int room_number)
{
    int num_visited;
    do {
        num_visited = 0;
        for (int i=1; i<=M*N; i++) {
            if (room[i]==-1) {
                rooms[room_number].insert(i), castle[0][i] = room_number;
                num_visited++;
                room[i] = room_number;
                if (castle[i][i+1] && !room[i+1])
                    rooms[room_number].insert(i+1), castle[0][i+1] = room_number, room[i+1] = -1;
                if (i>1 && castle[i][i-1] && !room[i-1])
                    rooms[room_number].insert(i-1), castle[0][i-1] = room_number, room[i-1] = -1;
                if (i<=M*(N-1) && castle[i][i+M] && !room[i+M])
                    rooms[room_number].insert(i+M), castle[0][i+M] = room_number, room[i+M] = -1;
                if (i>M && castle[i][i-M] && !room[i-M])
                    rooms[room_number].insert(i-M), castle[0][i-M] = room_number, room[i-M] = -1;
            }
        }
    } while (num_visited);
}

int number_of_rooms()
{
    int room_number = 0;
    for (int i=1; i<=M*N; i++)
        if (room[i]==0) {
            room_number++;
            room[i] = -1;
            flood_fill(room_number);
        }
    return room_number;
}
*/
int main()
{
    ifstream fin("castle.in");
    ofstream fout("castle.out");
    fin >> M >> N;
    int number;
    
    for (int i=1; i<=M*N; i++) {
        fin >> number;
        castle[i][0] = number;
    }
    for (int i=1; i<=M*N; i++) {
        if ((castle[i][0]%8)<4)
            castle[i+1][i] = castle[i][i+1] = 1;
        if (castle[i][0]<8)
            castle[i+M][i] = castle[i][i+M] = 1;
    }
    /*
    int total_rooms = number_of_rooms();
    fout << total_rooms << endl;
    for (int i=1; i<=total_rooms; i++) {
        maximum = max(maximum, int(rooms[i].size()));
    }
    fout << maximum << endl;
    int i = 1, j = 2;
    while (i<=total_rooms) {
        for (int a: rooms[i]) {
            while (j<=total_rooms) {
                for (int b: rooms[j]) {
                    if ((abs(a-b)==1&&!((a%M==0&&b%M==1)||(b%M==0&&a%M==1)))||abs(a-b)==M)
                        max_size = max(max_size, int(rooms[i].size()+rooms[j].size()));
                }
                j++;
                if (j==i)
                    j++;
            }
            if (i==1) j=2;
            else j=1;
        }
        i++;
    }
    fout << max_size << endl;
    for (int i=M*(N-1)+1; i<=M*N; i=i-M>0?i-M:i+M*(N-1)+1) {
        if(i>M && rooms[castle[0][i]].size() + rooms[castle[0][i-M]].size() == max_size) {
            fout << (i+M-1)/N << " " << i%M << " " << "N" << endl;
            break;
        }
        if(rooms[castle[0][i]].size() + rooms[castle[0][i+1]].size() == max_size) {
            fout << (i+M-1)/M << " " << i%M << " " << "E" << endl;
            break;
        }
    }*/
    return 0;
}