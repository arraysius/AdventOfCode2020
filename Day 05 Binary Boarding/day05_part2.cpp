#include <bits/stdc++.h>

using namespace std;

int main() {
    bool seatIds[1024];

    string seq;
    while (cin >> seq) {
        int row, col;

        // Binary search row
        int low = 0, high = 127;
        for (int i = 0; i < 7; i++) {
            if (seq[i] == 'F') {
                high = (low + high) / 2;
            } else {
                low = ((low + high) / 2) + 1;
            }
        }
        row = low;

        // Binary search col
        low = 0, high = 7;
        for (int i = 7; i < 10; i++) {
            if (seq[i] == 'L') {
                high = (low + high) / 2;
            } else {
                low = ((low + high) / 2) + 1;
            }
        }
        col = low;

        int seatId = (row * 8) + col;
        seatIds[seatId] = true;
    }

    for (int i = 0; i < 1024; i++) {
        if (i - 1 >= 0 && i + 1 <= 1023 && !seatIds[i] && seatIds[i - 1] && seatIds[i + 1]) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}