#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("day06_input.txt");

    int sum = 0, groupSize = 0;
    unordered_map<char, int> questions;
    do {
        string line;
        getline(file, line);

        if (line.empty()) {
            for (pair<char, int> p : questions) {
                if (p.second == groupSize) {
                    sum++;
                }
            }

            questions.clear();
            groupSize = 0;
            continue;
        } else {
            groupSize++;
        }

        for (char c : line) {
            questions.emplace(make_pair(c, 0));
            questions[c]++;
        }
    } while (!file.eof());

    cout << sum << endl;

    return 0;
}