#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("day14_input.txt");

    unordered_map<unsigned long long, int> memory;
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

            vector<int> floatingPos;
            array<int, 36> binary;
            binary.fill(0);
            for (int i = 0; i < 36; i++) {
                if (mask[35 - i] == 'X') {
                    binary[35 - i] = 0;
                    floatingPos.push_back(35 - i);
                } else if (mask[35 - i] == '1') {
                    binary[35 - i] = 1;
                } else if (i < 32) {
                    binary[35 - i] = (add >> i) & 1;
                }
            }

            vector<array<int, 36>> addresses;
            for (int p : floatingPos) {
                if (addresses.size() == 0) {
                    array<int, 36> newAddress = binary;
                    for (int j = 0; j < 2; j++) {
                        newAddress[p] = j;
                        addresses.push_back(newAddress);
                    }
                } else {
                    int prevAddresses = addresses.size();
                    for (int i = 0; i < prevAddresses; i++) {
                        array<int, 36> newAddress = addresses[i];
                        for (int j = 0; j < 2; j++) {
                            newAddress[p] = j;
                            addresses.push_back(newAddress);
                        }
                    }
                }
            }

            for (array<int, 36> binAddress : addresses) {
                // binary to int
                unsigned long long address = 0;
                for (int i = 0; i < 36; i++) {
                    address += binAddress[35 - i] * pow(2, i);
                }

                // update memory
                unordered_map<unsigned long long, int>::iterator it =
                    memory.find(address);
                if (it == memory.end()) {
                    memory.insert(make_pair(address, val));
                } else {
                    it->second = val;
                }
            }
        }
    }

    unsigned long long sum = 0;
    for (pair<unsigned long long, int> m : memory) {
        sum += m.second;
    }

    cout << sum << endl;

    return 0;
}