#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("day01_input.txt");

    unordered_set<int> nums;

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        int num;
        while (iss >> num) {
            bool found = false;

            for (int i : nums) {
                int diff = 2020 - num - i;
                if (nums.find(diff) != nums.end()) {
                    cout << num << " " << i << " " << diff << endl;
                    cout << num * i * diff << endl;
                    break;
                } else {
                    found = false;
                }
            }

            if (!found) {
                nums.insert(num);
            }
        }
    }

    return 0;
}