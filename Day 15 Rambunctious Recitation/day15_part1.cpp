#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("day15_input.txt");

    unordered_map<int, int> age;

    int i = 1, nextNum;
    string line;

    for (i; getline(file, line, ','); i++) {
        int n = stoi(line);
        age.insert(make_pair(n, i));
        nextNum = n;
        // cout << i << ": " << n << endl;
    }
    age.erase(nextNum);
    i--;

    for (i; i < 2020; i++) {
        unordered_map<int, int>::iterator it = age.find(nextNum);
        if (it == age.end()) {
            age.insert(make_pair(nextNum, i));
            nextNum = 0;
        } else {
            nextNum = i - it->second;
            it->second = i;
        }
        // cout << i + 1 << ": " << nextNum << endl;
    }

    cout << i << ": " << nextNum << endl;

    return 0;
}