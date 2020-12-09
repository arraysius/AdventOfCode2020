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
                int byr = stoi(value);
                if (byr >= 1920 && byr <= 2002) {
                    passport->byr = byr;
                }
            } else if (parameter == "iyr") {
                int iyr = stoi(value);
                if (iyr >= 2010 && iyr <= 2020) {
                    passport->iyr = iyr;
                }
            } else if (parameter == "eyr") {
                int eyr = stoi(value);
                if (eyr >= 2020 && eyr <= 2030) {
                    passport->eyr = eyr;
                }
            } else if (parameter == "hgt" &&
                       regex_match(value, regex("(\\d+)(cm|in)"))) {
                int hgt;
                string unit;
                istringstream hgtIss(value);
                hgtIss >> hgt >> unit;

                if ((unit == "cm" && hgt >= 150 && hgt <= 193) ||
                    (unit == "in" && hgt >= 59 && hgt <= 76)) {
                    passport->hgt = value;
                }
            } else if (parameter == "pid" &&
                       regex_match(value, regex("[\\d+]{9}"))) {
                passport->pid = value;
            } else if (parameter == "cid") {
                passport->cid = stoi(value);
            } else if (parameter == "hcl" &&
                       regex_match(value, regex("#[0-9a-f]{6}"))) {
                passport->hcl = value;
            } else if (parameter == "ecl" &&
                       regex_match(value,
                                   regex("amb|blu|brn|gry|grn|hzl|oth"))) {
                passport->ecl = value;
            }
        }
    } while (!file.eof());

    cout << validPassports << endl;

    return 0;
}