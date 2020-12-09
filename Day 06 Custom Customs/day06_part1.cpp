#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("day06_input.txt");

    int sum = 0;
    unordered_set<char> questions;
    do {
        string line;
        getline(file, line);

        if (line.empty()) {
            sum += questions.size();
            questions.clear();
            continue;
        }

        for (char c : line) {
            questions.insert(c);
        }
    } while (!file.eof());

    cout << sum << endl;

    return 0;
}