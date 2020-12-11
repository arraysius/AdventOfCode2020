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
                    int occupiedVisibleSeats = 0;
                    for (int k = 0; k < 8; k++) {
                        for (int multiple = 1;
                             i + (multiple * dy[k]) >= 0 &&
                             i + (multiple * dy[k]) < grid.size() &&
                             j + (multiple * dx[k]) >= 0 &&
                             j + (multiple * dx[k]) <
                                 grid[i + (multiple * dy[k])].size();
                             multiple++) {
                            if (grid[i + (multiple * dy[k])]
                                    [j + (multiple * dx[k])] == '#') {
                                occupiedVisibleSeats++;
                                break;
                            } else if (grid[i + (multiple * dy[k])]
                                           [j + (multiple * dx[k])] == 'L') {
                                break;
                            }
                        }
                    }

                    if (grid[i][j] == 'L' && occupiedVisibleSeats == 0) {
                        newGrid[i][j] = '#';
                    } else if (grid[i][j] == '#' && occupiedVisibleSeats >= 5) {
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