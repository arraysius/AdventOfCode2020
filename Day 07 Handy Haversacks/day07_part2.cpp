#include <bits/stdc++.h>

using namespace std;

unordered_map<string, vector<pair<string, int>>> childBags;

int countBags(string bagColour) {
    unordered_map<string, vector<pair<string, int>>>::iterator parentBag =
        childBags.find(bagColour);

    if (parentBag != childBags.end()) {
        int bags = 0;
        for (pair<string, int> p : parentBag->second) {
            bags += p.second + (p.second * countBags(p.first));
        }
        return bags;
    } else {
        return 0;
    }
}

int main() {
    ifstream file("day07_input.txt");

    string line;
    while (getline(file, line)) {
        // Get parent bag colour
        regex parentBagRegex("^[a-zA-z]+ [a-zA-z]+");
        smatch sm;
        regex_search(line, sm, parentBagRegex);
        string parentBagColour = sm[0].str();

        // Get child bag colour
        regex childBagRegex("(\\d+) ([a-zA-Z]+ [a-zA-Z]+)");
        for (sregex_iterator i =
                 sregex_iterator(line.begin(), line.end(), childBagRegex);
             i != sregex_iterator(); i++) {
            smatch matches = *i;
            int childBagQuantity = stoi(matches[1].str());
            string childBagColour = matches[2].str();

            // Add parent and child bag colour to child bag map
            unordered_map<string, vector<pair<string, int>>>::iterator
                parentBag = childBags.find(parentBagColour);
            if (parentBag == childBags.end()) {
                childBags.insert(make_pair(
                    parentBagColour, vector<pair<string, int>>{make_pair(
                                         childBagColour, childBagQuantity)}));
            } else {
                (parentBag->second)
                    .push_back(make_pair(childBagColour, childBagQuantity));
            }
        }
    }

    cout << countBags("shiny gold") << endl;

    return 0;
}