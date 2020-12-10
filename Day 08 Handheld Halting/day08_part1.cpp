#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("day08_input.txt");

    vector<pair<string, int>> instructions;
    vector<bool> visited;

    string op;
    int val;
    while (file >> op >> val) {
        instructions.push_back(make_pair(op, val));
        visited.push_back(false);
    }

    int acc = 0;
    for (int i = 0; i < instructions.size();) {
        op = instructions[i].first;
        val = instructions[i].second;

        if (visited[i]) {
            break;
        } else {
            visited[i] = true;
        }

        if (op == "acc") {
            acc += val;
            i++;
        } else if (op == "jmp") {
            i += val;
        } else {
            i++;
        }
    }

    cout << acc << endl;

    return 0;
}