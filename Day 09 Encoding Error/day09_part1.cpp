#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("day09_input.txt");

    deque<int> previousNumbers;

    // Read preamble numbers
    for (int i = 0; i < 25; i++) {
        int n;
        file >> n;
        previousNumbers.push_back(n);
    }

    // Find invalid number
    int nextNum;
    while (file >> nextNum) {
        bool found = false;
        for (int n : previousNumbers) {
            if (find(previousNumbers.begin(), previousNumbers.end(), nextNum - n) != previousNumbers.end() && nextNum - n != n) {
                found = true;
                break;
            }
        }

        if (!found) {
            cout << nextNum << endl;
            return 0;
        }

        previousNumbers.pop_front();
        previousNumbers.push_back(nextNum);
    }

    return 0;
}