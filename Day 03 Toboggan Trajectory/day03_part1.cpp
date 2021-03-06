#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("day03_input.txt");

    int mapWidth = 31;
    int trees = 0;
    int posX = 0;

    string line;
    getline(file, line);
    while (getline(file, line)) {
        posX += 3;
        posX %= mapWidth;
        if (line[posX] == '#') {
            trees++;
        }
    }

    cout << trees << endl;

    return 0;
}