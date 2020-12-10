#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("day10_input.txt");

    vector<int> adapters;
    // Initial jolt diff from outlet
    adapters.push_back(0);

    int adapter;
    while (file >> adapter) {
        adapters.push_back(adapter);
    }

    sort(adapters.begin(), adapters.end());
    // Final jolt diff to device
    adapters.push_back(adapters.back() + 3);

    int joltDiff[4] = {0, 0, 0, 0};
    for (int i = 0; i < adapters.size() - 1; i++) {
        joltDiff[adapters[i + 1] - adapters[i]]++;
    }
    cout << joltDiff[1] << " " << (joltDiff[3]) << endl;
    cout << joltDiff[1] * (joltDiff[3]) << endl;

    return 0;
}