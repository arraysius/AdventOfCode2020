#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("day13_input.txt");

    unsigned long long startTime, endTime;

    // First value ignored
    int ignored;
    file >> ignored;

    vector<int> sequence;

    string line;
    while (getline(file, line, ',')) {
        if (line == "x") {
            sequence.push_back(-1);
            continue;
        }

        int busId = stoi(line);
        sequence.push_back(busId);
    }

    // unsigned long long timestamp = 0;
    // larger than 100000000000000
    unsigned long long timestamp =
        ((100000000000000 / sequence[0]) + 1) * sequence[0];
    unsigned long long increment = sequence[0];
    int seqStart = 1;
    for (timestamp; seqStart < sequence.size(); timestamp += increment) {
        if (timestamp == 77 || timestamp == 350) {
            cout << endl;
        }

        int j = seqStart;
        for (j; j < sequence.size(); j++) {
            if (sequence[j] == -1) {
                continue;
            } else if ((timestamp + j) % sequence[j] == 0) {
                increment *= sequence[j];
                seqStart = j + 1;
                break;
            } else {
                break;
            }
        }
    }

    cout << timestamp % increment << endl;

    return 0;
}