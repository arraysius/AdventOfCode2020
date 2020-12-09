#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("day02_input.txt");

    int validPasswords = 0;

    string line;
    while (getline(file, line)) {
        int min, max;
        char letter, temp;
        string password;

        istringstream iss(line);
        while (iss >> min >> temp >> max >> letter >> temp >> password) {
            min--;
            max--;

            if ((password[min] == letter && password[max] != letter) ||
                (password[min] != letter && password[max] == letter)) {
                validPasswords++;
            }
        }
    }

    cout << validPasswords << endl;

    return 0;
}