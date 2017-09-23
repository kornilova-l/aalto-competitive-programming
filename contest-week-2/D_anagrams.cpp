#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<string, set<string>> myMap; // normalized name to names
    string word;
    getline(cin, word);
    for (int i = 0; i < n; i++) {
        getline(cin, word);
        multiset<char> chars;
        for (int j = 0; word[j] != 0 && j < 32; j++) {
            chars.insert(word[j]);
        }
        char normalzed[word.length() + 1];
        int j = 0;
        for (auto c : chars) {
            normalzed[j] = c;
            j++;
        }
        normalzed[word.length() + 1] = 0;
        myMap[string(normalzed)].insert(word);
    }
    vector<set<string>> res;
    for (auto entry : myMap) {
        if (entry.second.size() > 1) {
            unsigned long index = res.size();
            set<string> mySet;
            res.push_back(mySet);
            for (auto word : entry.second) {
                res[index].insert(word);
            }
        }
    }
    cout << res.size() << endl;
    for (auto words : res) {
        cout << words.size() << endl;
        for (auto word : words) {
            cout << word << endl;
        }
    }
}

