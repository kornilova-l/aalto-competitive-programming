#include <iostream>
#include <set>
#include <unordered_map>
#include <string.h>
#include <vector>

using namespace std;

void dfs(int index, unordered_map<int, set<int>> &roads, vector<int> &processed, bool *visited) {
    if (visited[index]) {
        return;
    }
    visited[index] = true;
    for (auto nextIntersection : roads[index]) {
        dfs(nextIntersection, roads, processed, visited);
    }
    processed.push_back(index);
}

void dfsUpdateComponent(unordered_map<int, set<int>> &reversed,
                        int intersection,
                        set<int> &component,
                        bool *visited,
                        set<int> &checked) {
    if (visited[intersection]) {
        return;
    }
    visited[intersection] = true;
    component.insert(intersection);
    checked.insert(intersection);
    for (auto destination : reversed[intersection]) {
        dfsUpdateComponent(reversed, destination, component, visited, checked);
    }
}

bool connected(int current, int wantedDest, unordered_map<int, set<int>> &roads, bool *visited) {
    if (visited[current]) {
        return false;
    }
    visited[current] = true;
    if (current == wantedDest) {
        return true;
    }
    for (auto dest : roads[current]) {
        if (connected(dest, wantedDest, roads, visited)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n; // number of intersections
    int m; // number of roads
    cin >> n >> m;
    unordered_map<int, set<int>> roads;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        roads[a].insert(b);
    }
    vector<int> processed;
    bool visited[n];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, roads, processed, visited);
        }
    }
    unordered_map<int, set<int>> reversed;
    for (auto myPair : roads) {
        for (auto destination : myPair.second) {
            reversed[destination].insert(myPair.first);
        }
    }
    vector<set<int>> components;
    set<int> checked;
    memset(visited, false, sizeof(visited));
    for (int i = n - 1; i >= 0; i--) {
        int intersection = processed[i];
        if (checked.find(intersection) == checked.end()) { // if does not belong to component
            set<int> newComponent;
            dfsUpdateComponent(reversed, intersection, newComponent, visited, checked);
            components.push_back(newComponent);
        }
    }
    if (components.size() == 0) {
        cout << "ERROR";
    }
    if (components.size() == 1) {
        cout << "YES";
        return 0;
    }
    cout << "NO" << endl;
    for (auto i : components[0]) {
        for (auto j : components[1]) {
            memset(visited, false, sizeof(visited));
            if (!connected(i, j, roads, visited)) {
                cout << i << " " << j;
                return 0;
            }
            if (!connected(j, i, roads, visited)) {
                cout << j << " " << i;
                return 0;
            }
        }
    }
    return 0;
}