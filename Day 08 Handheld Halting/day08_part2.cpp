#include <bits/stdc++.h>

using namespace std;

int swapOp(vector<pair<string, int>> instructions, vector<bool> visited, int i,
           int acc) {
    string op = instructions[i].first;
    int val = instructions[i].second;

    if (op == "jmp") {
        op = "nop";
    } else if (op == "nop") {
        op = "jmp";
    }

    instructions[i] = make_pair(op, val);

    for (i; i < instructions.size();) {
        op = instructions[i].first;
        val = instructions[i].second;

        if (visited[i]) {
            acc = -1;
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

    return acc;
}

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

        if (op == "jmp" || op == "nop") {
            int swapAcc = swapOp(instructions, visited, i, acc);
            if (swapAcc > 0) {
                cout << swapAcc << endl;
                return 0;
            }
        }

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

    return 0;
}