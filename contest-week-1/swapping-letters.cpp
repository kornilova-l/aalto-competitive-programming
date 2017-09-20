#include <iostream>
#include <vector>
#include <map>

typedef std::multimap<char, char>::iterator MMAPIterator;

using namespace std;

char lettersCount = 'z' - 'a' + 1;

int getSmallestPos(char *s, int i, multimap<char, char> pairs, vector<int> layers[]) {
    char c = s[i];
    int worst = 0;
    if (layers[c - 'a'].size() != 0) {
        worst = layers[c - 'a'].back() + 1;
    }
    // get all pairs of c.
    // find worst of this positions
    pair<MMAPIterator, MMAPIterator> rangeIterators = pairs.equal_range(c);
    for (MMAPIterator it = rangeIterators.first; it != rangeIterators.second; it++) {
        char pair = it->second;
        if (layers[pair - 'a'].size() != 0) {
            int maybeWorst = layers[pair - 'a'].back() + 1;
            if (maybeWorst > worst) {
                worst = maybeWorst;
            }
        }
    }
    return worst;
}

void initLayers(vector<int> layers[], char *s, multimap<char, char> pairs) {
    for (int i = 0; s[i] != 0 && i < 1000000; i++) {
        layers[s[i] - 'a'].push_back(getSmallestPos(s, i, pairs, layers));
    }
}

bool layersEqual(vector<int> layers1[], vector<int> layers2[]) {
    for (int i = 0; i < lettersCount; i++) {
        if (layers1[i] != layers2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    multimap<char, char> pairs;
    for (int i = 0; i < n; i++) {
        char c1, c2;
        cin >> c1 >> c2;
        pairs.insert({c1, c2});
        pairs.insert({c2, c1});
    }
    char s1[1000000], s2[1000000];
    cin.getline(s1, 1000000);
    cin.getline(s1, 1000000);
    cin.getline(s2, 1000000);
    vector<int> layers1[lettersCount];
    vector<int> layers2[lettersCount];
    initLayers(layers1, s1, pairs);
    initLayers(layers2, s2, pairs);
    if (layersEqual(layers1, layers2)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}

// 1
// a b
// cddecabc
// cddebacc

// NO
