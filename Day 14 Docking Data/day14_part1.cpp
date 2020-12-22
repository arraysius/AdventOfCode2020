#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("day14_input.txt");

    unordered_map<int, unsigned long long> memory;
    string mask;

    string line;
    while (getline(file, line, '=')) {
        int add, val;
        if (line == "mask ") {
            // mask
            getline(file, mask);
            mask = mask.substr(1, mask.size() - 1);
        } else {
            // mem
            sscanf(line.c_str(), "mem[%d]", &add);

            getline(file, line);
            val = stoi(line);

            unsigned long long maskedVal = 0;
            for (int i = 0; i < 36; i++) {
                if (mask[35 - i] != 'X') {
                    maskedVal += (mask[35 - i] - '0') * pow(2, i);
                } else if (i < 32) {
                    maskedVal += ((val >> i) & 1) * pow(2, i);
                }
            }

            // update memory
            unordered_map<int, unsigned long long>::iterator it =
                memory.find(add);
            if (it == memory.end()) {
                memory.insert(make_pair(add, maskedVal));
            } else {
                it->second = maskedVal;
            }
        }
    }

    unsigned long long sum = 0;
    for (pair<int, unsigned long long> m : memory) {
        sum += m.second;
    }

    cout << sum << endl;

    return 0;
}