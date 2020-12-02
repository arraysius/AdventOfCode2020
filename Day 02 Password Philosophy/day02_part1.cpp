#include <bits/stdc++.h>

using namespace std;

int main() {
    int validPasswords = 0;

    string line;
    while (getline(cin, line)) {
        int min, max;
        char letter, temp;
        string password;

        istringstream iss(line);
        while (iss >> min >> temp >> max >> letter >> temp >> password) {
            int letterCount = 0;
            for (char c : password) {
                if (c == letter) {
                    letterCount++;
                }
            }

            if (letterCount >= min && letterCount <= max) {
                validPasswords++;
            }
        }
    }

    cout << validPasswords << endl;

    return 0;
}