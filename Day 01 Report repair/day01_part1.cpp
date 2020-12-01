#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_set<int> nums;

    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        int num;
        while (iss >> num) {
            int second_num = 2020 - num;
            if (nums.find(second_num) != nums.end()) {
                cout << num << " " << second_num << endl;
                cout << num * second_num << endl;
                break;
            } else {
                nums.insert(num);
            }
        }
    }

    return 0;
}