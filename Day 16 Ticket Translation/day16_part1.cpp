#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("day16_input.txt");

    vector<array<int, 4>> fields;

    string line;
    for (int i = 0; i < 20; i++) {
        string field;
        int firstLow, firstHigh, secondLow, secondHigh;

        getline(file, field, ':');
        getline(file, line);
        sscanf(line.c_str(), " %d-%d or %d-%d", &firstLow, &firstHigh,
               &secondLow, &secondHigh);

        fields.push_back(array<int, 4>{firstLow, firstHigh, secondLow, secondHigh});
    }

    getline(file, line);
    // your ticket:
    getline(file, line);
    getline(file, line);

    getline(file, line);
    // nearby tickets:
    getline(file, line);

    int errorRate = 0;
    while (getline(file, line)) {
        istringstream iss(line);
        string v;
        while (getline(iss, v, ',')) {
            int val = stoi(v);
            bool valid = false;

            for (array<int, 4> arr : fields) {
                bool inRange = (val >= arr[0] && val <= arr[1]) ||
                               (val >= arr[2] && val <= arr[3]);
                if (inRange) {
                    valid = true;
                    break;
                }
            }

            if (!valid) {
                errorRate += val;
            }
        };
    }

    cout << errorRate << endl;

    return 0;
}