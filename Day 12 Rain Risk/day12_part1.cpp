#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("day12_input.txt");

    int ns = 0, ew = 0;

    char directions[] = {'N', 'E', 'S', 'W'};
    char faceDir = 'E', action;
    int val, faceDirIndex;
    while (file >> action >> val) {
        switch (action) {
            case 'N':
                ns += val;
                break;
            case 'S':
                ns -= val;
                break;
            case 'E':
                ew += val;
                break;
            case 'W':
                ew -= val;
                break;
            case 'F':
                switch (faceDir) {
                    case 'N':
                        ns += val;
                        break;
                    case 'S':
                        ns -= val;
                        break;
                    case 'E':
                        ew += val;
                        break;
                    case 'W':
                        ew -= val;
                        break;
                }
                break;
            case 'L':
                faceDirIndex =
                    distance(begin(directions),
                             find(begin(directions), end(directions), faceDir));
                faceDir = directions[(faceDirIndex - (val / 90) + 4) % 4];
                break;
            case 'R':
                faceDirIndex =
                    distance(begin(directions),
                             find(begin(directions), end(directions), faceDir));
                faceDir = directions[(faceDirIndex + (val / 90)) % 4];
                break;
        }
    }

    cout << abs(ns) + abs(ew) << endl;

    return 0;
}