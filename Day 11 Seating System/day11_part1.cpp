#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("day11_input.txt");

    vector<vector<char>> grid;

    string line;
    for (int i = 0; getline(file, line); i++) {
        grid.push_back(vector<char>{});
        for (char c : line) {
            grid[i].push_back(c);
        }
    }

    vector<vector<char>> newGrid = grid;
    do {
        grid = newGrid;

        int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 'L' || grid[i][j] == '#') {
                    int occupiedAdjSeats = 0;
                    for (int k = 0; k < 8; k++) {
                        if (i + dy[k] >= 0 && i + dy[k] < grid.size() &&
                            j + dx[k] >= 0 &&
                            j + dx[k] < grid[i + dy[k]].size() &&
                            grid[i + dy[k]][j + dx[k]] == '#') {
                            occupiedAdjSeats++;
                        }
                    }

                    if (grid[i][j] == 'L' && occupiedAdjSeats == 0) {
                        newGrid[i][j] = '#';
                    } else if (grid[i][j] == '#' && occupiedAdjSeats >= 4) {
                        newGrid[i][j] = 'L';
                    }
                }
            }
        }
    } while (grid != newGrid);

    int occupiedSeats = 0;
    for (vector<char> row : newGrid) {
        for (char pos : row) {
            if (pos == '#') {
                occupiedSeats++;
            }
        }
    }

    cout << occupiedSeats << endl;

    return 0;
}