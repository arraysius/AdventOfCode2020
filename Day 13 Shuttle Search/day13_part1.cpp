#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("day13_input.txt");

    int timestamp;
    file >> timestamp;

    // <busId, nextDeparture>
    pair<int, int> nextBus = make_pair(-1, -1);

    string line;
    while (getline(file, line, ',')) {
        if (line == "x") {
            continue;
        }

        int busId = stoi(line);

        int nextDeparture = ((timestamp / busId) + 1) * busId;
        if (nextDeparture < nextBus.second || nextBus.second == -1) {
            nextBus = make_pair(busId, nextDeparture);
        }
    }

    cout << nextBus.first << " " << nextBus.second << endl;
    cout << nextBus.first * (nextBus.second - timestamp) << endl;

    return 0;
}