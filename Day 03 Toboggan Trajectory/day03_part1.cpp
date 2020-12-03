#include <bits/stdc++.h>

using namespace std;

int main() {
    int mapWidth = 31;
    int trees = 0;
    int posX = 0;

    string line;
    getline(cin, line);
    while (getline(cin, line)) {
        posX += 3;
        posX %= mapWidth;
        if (line[posX] == '#') {
            trees++;
        }
    }

    cout << trees << endl;

    return 0;
}