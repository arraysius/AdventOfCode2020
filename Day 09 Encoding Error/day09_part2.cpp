#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("day09_input.txt");

    vector<int> numbers;
    deque<int> previousNumbers;

    // Read preamble numbers
    for (int i = 0; i < 25; i++) {
        int n;
        file >> n;
        previousNumbers.push_back(n);
        numbers.push_back(n);
    }

    // Find invalid number
    int nextNum;
    while (file >> nextNum) {
        bool found = false;
        for (int n : previousNumbers) {
            if (find(previousNumbers.begin(), previousNumbers.end(),
                     nextNum - n) != previousNumbers.end() &&
                nextNum - n != n) {
                found = true;
                break;
            }
        }

        if (!found) {
            break;
        }

        previousNumbers.pop_front();
        previousNumbers.push_back(nextNum);
        numbers.push_back(nextNum);
    }

    // Find contiguous set of numbers
    int invalidNum = nextNum;
    for (int i = 0; i < numbers.size(); i++) {
        int j = i;
        vector<int> contiguousList = {numbers[j]};
        int sum = numbers[j];
        while (j + 1 < numbers.size()) {
            sum += numbers[++j];
            contiguousList.push_back(numbers[j]);
            if (sum == invalidNum) {
                cout << *min_element(contiguousList.begin(),
                                     contiguousList.end())
                     << " + "
                     << *max_element(contiguousList.begin(),
                                     contiguousList.end())
                     << " = "
                     << *min_element(contiguousList.begin(),
                                     contiguousList.end()) +
                            *max_element(contiguousList.begin(),
                                         contiguousList.end())
                     << endl;
                return 0;
            } else if (sum < invalidNum) {
                continue;
            } else {
                break;
            }
        }
    }

    return 0;
}