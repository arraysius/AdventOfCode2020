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

    unsigned long long waysToReach[adapters.size()];
    fill_n(waysToReach, adapters.size(), 0);

    waysToReach[0] = 1;
    for (int i = 0; i < adapters.size(); i++) {
        for (int j = 1; j <= 3; j++) {
            if (i + j < adapters.size() && adapters[i + j] - adapters[i] <= 3) {
                waysToReach[i + j] += waysToReach[i];
            }
        }
    }

    cout << waysToReach[adapters.size() - 1] << endl;

    return 0;
}