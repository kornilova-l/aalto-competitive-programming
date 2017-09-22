#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <time.h>

using namespace std;

char lettersCount = 'z' - 'a' + 1;

void decide(unordered_map<char, set<char>> pairsMap, char s1[1000000], char s2[1000000]);

void printVector(vector<int> vector);

#define SIZE 1000000

void initLayers(vector<int> layers[], char *s, unordered_map<char, set<char>> pairsMap) {
    for (int i = 0; s[i] != 0 && i < SIZE; i++) {
        char c = s[i];
        int smallestPos = 0;
        if (layers[c - 'a'].size() != 0) {
            smallestPos = layers[c - 'a'].back() + 1;
        }
        for (auto pair : pairsMap[c]) {
            if (layers[pair - 'a'].size() != 0) {
                smallestPos = max(layers[pair - 'a'].back() + 1, smallestPos);
            }
        }
        layers[c - 'a'].push_back(smallestPos);
    }
}

int main() {
//    int n;
//    cin >> n;
//    unordered_map<char, set<char>> pairsMap;
//    for (int i = 0; i < n; i++) {
//        char c1, c2;
//        cin >> c1 >> c2;
//        pairsMap[c1].insert(c2);
//        pairsMap[c2].insert(c1);
//    }
//    char s1[SIZE], s2[SIZE];
//    cin.getline(s1, SIZE);
//    cin.getline(s1, SIZE);
//    cin.getline(s2, SIZE);
    srand(time(0));
    int n = 2;
    unordered_map<char, set<char>> pairsMap;
    pairsMap['a'].insert('b');
    pairsMap['a'].insert('c');
    pairsMap['b'].insert('a');
    pairsMap['c'].insert('a');
    char s1[SIZE];
    char s2[SIZE];
    for (int i = 0; i < 10; i++) {
        s1[i] = rand() % 5 + 'a';
        s2[i] = rand() % 5 + 'a';
    }
    s1[10] = 0;
    s2[10] = 0;
    cout << s1 << endl;
    cout << s2 << endl;
    decide(pairsMap, s1, s2);
}

void decide(unordered_map<char, set<char>> pairsMap, char s1[1000000], char s2[1000000]) {
    vector<int> layers1[lettersCount];
    vector<int> layers2[lettersCount];
    initLayers(layers1, s1, pairsMap);
    initLayers(layers2, s2, pairsMap);
    for (int i = 0; i < lettersCount; i++) {
        cout << (char) 'a' + i << ": ";
        printVector(layers1[i]);
    }
    for (int i = 0; i < lettersCount; i++) {
        if (layers1[i] != layers2[i]) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";

}

// 1
// a b
// cddecabc
// cddebacc

// NO
/*
2
a b
a c
ereeabreac
reeacberea

 NO
 */
