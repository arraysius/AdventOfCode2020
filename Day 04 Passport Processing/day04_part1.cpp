#include <bits/stdc++.h>

using namespace std;

struct Passport {
    int byr = -1;
    int iyr = -1;
    int eyr = -1;
    string hgt = "";
    string pid = "";
    int cid = -1;
    string hcl = "";
    string ecl = "";
};

int main() {
    ifstream file("day04_input.txt");

    int validPassports = 0;
    Passport* passport = new Passport;

    do {
        string line;
        getline(file, line);

        if (line == "") {
            // Parse passport fields
            bool validPassport = (passport->byr > 0) && (passport->iyr > 0) &&
                                 (passport->eyr > 0) && (passport->hgt != "") &&
                                 (passport->pid != "") &&
                                 (passport->hcl != "") && (passport->ecl != "");
            if (validPassport) {
                validPassports++;
            }

            // Reset passport fields
            delete passport;
            passport = new Passport;
            continue;
        }

        // Read passport fields
        istringstream iss(line);
        string parameter, value;
        while (getline(iss, parameter, ':')) {
            getline(iss, value, ' ');

            if (parameter == "byr") {
                passport->byr = stoi(value);
            } else if (parameter == "iyr") {
                passport->iyr = stoi(value);
            } else if (parameter == "eyr") {
                passport->eyr = stoi(value);
            } else if (parameter == "hgt") {
                passport->hgt = value;
            } else if (parameter == "pid") {
                passport->pid = value;
            } else if (parameter == "cid") {
                passport->cid = stoi(value);
            } else if (parameter == "hcl") {
                passport->hcl = value;
            } else if (parameter == "ecl") {
                passport->ecl = value;
            }
        }
    } while (!file.eof());

    cout << validPassports << endl;

    return 0;
}