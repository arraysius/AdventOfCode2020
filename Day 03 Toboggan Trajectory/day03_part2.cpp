#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("day03_input.txt");

    int mapWidth = 31;
    int trees[] = {0, 0, 0, 0, 0};
    pair<int, int> slopes[] = {make_pair(1, 1), make_pair(3, 1),
                               make_pair(5, 1), make_pair(7, 1),
                               make_pair(1, 2)};
    int pos[] = {0, 0, 0, 0, 0};

    int lineNum = 1;
    string line;
    getline(file, line);
    while (getline(file, line)) {
        // Count first 4 slopes
        for (int i = 0; i <= 3; i++) {
            pos[i] += slopes[i].first;
            pos[i] %= mapWidth;

            if (line[pos[i]] == '#') {
                trees[i]++;
            }
        }

        // Count last slope
        if (lineNum % 2 == 0) {
            pos[4] += slopes[4].first;
            pos[4] %= mapWidth;

            if (line[pos[4]] == '#') {
                trees[4]++;
            }
        }

        lineNum++;
    }

    unsigned long long finalValue = 1;
    for (int tree : trees) {
        cout << tree << " ";
        finalValue *= tree;
    }
    cout << endl << finalValue << endl;

    return 0;
}