#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("day12_input.txt");

    int ns = 0, ew = 0;

    int waypoint[] = {1, 10, 0, 0}, temp[4];
    char action;
    int val;
    while (file >> action >> val) {
        switch (action) {
            case 'N':
                waypoint[2] > 0 ? waypoint[2] -= val : waypoint[0] += val;
                if (waypoint[2] < 0) {
                    waypoint[0] = -1 * waypoint[2];
                    waypoint[2] = 0;
                }
                break;
            case 'S':
                waypoint[0] > 0 ? waypoint[0] -= val : waypoint[2] += val;
                if (waypoint[0] < 0) {
                    waypoint[2] = -1 * waypoint[0];
                    waypoint[0] = 0;
                }
                break;
            case 'E':
                waypoint[3] > 0 ? waypoint[3] -= val : waypoint[1] += val;
                if (waypoint[3] < 0) {
                    waypoint[1] = -1 * waypoint[3];
                    waypoint[3] = 0;
                }
                break;
            case 'W':
                waypoint[1] > 0 ? waypoint[1] -= val : waypoint[3] += val;
                if (waypoint[1] < 0) {
                    waypoint[3] = -1 * waypoint[1];
                    waypoint[1] = 0;
                }
                break;
            case 'F':
                ns += val * (waypoint[0] - waypoint[2]);
                ew += val * (waypoint[1] - waypoint[3]);
                break;
            case 'L':
                for (int i = 0; i < 4; i++) {
                    temp[i] = 0;
                }

                for (int j = 0; j < 4; j++) {
                    temp[(j - (val / 90) + 4) % 4] = waypoint[j];
                }

                copy(begin(temp), end(temp), begin(waypoint));
                break;
            case 'R':
                for (int k = 0; k < 4; k++) {
                    temp[k] = 0;
                }

                for (int l = 0; l < 4; l++) {
                    temp[(l + (val / 90)) % 4] = waypoint[l];
                }

                copy(begin(temp), end(temp), begin(waypoint));
                break;
        }
    }

    cout << abs(ns) + abs(ew) << endl;

    return 0;
}