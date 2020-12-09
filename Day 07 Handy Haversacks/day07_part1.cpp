#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream file("day07_input.txt");

    unordered_map<string, vector<pair<string, int>>> parentBags;

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

            // Add child and parent bag colour to parent bag map
            unordered_map<string, vector<pair<string, int>>>::iterator
                childBag = parentBags.find(childBagColour);
            if (childBag == parentBags.end()) {
                parentBags.insert(make_pair(
                    childBagColour, vector<pair<string, int>>{make_pair(
                                        parentBagColour, childBagQuantity)}));
            } else {
                (childBag->second)
                    .push_back(make_pair(parentBagColour, childBagQuantity));
            }
        }
    }

    unordered_set<string> possibleParentBagColours;
    queue<string> colourQueue;
    colourQueue.push("shiny gold");
    do {
        string bagColour = colourQueue.front();
        colourQueue.pop();

        if (parentBags.find(bagColour) != parentBags.end()) {
            for (pair<string, int> p : parentBags.find(bagColour)->second) {
                colourQueue.push(p.first);
                possibleParentBagColours.emplace(p.first);
            }
        }
    } while (colourQueue.size() > 0);

    cout << possibleParentBagColours.size() << endl;

    return 0;
}