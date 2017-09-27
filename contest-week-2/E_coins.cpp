#include<iostream>
#include<unordered_map>
#include<vector>
#include<set>
#include<string.h>
#include<queue>

#define ll long long

using namespace std;

void dfs(unordered_map<int, set<int>> &paths,
         int index, bool *visited, vector<int> &processed) {
    if (visited[index]) {
        return;
    }
    visited[index] = true;
    for (auto dest : paths[index]) {
        dfs(paths, dest, visited, processed);
    }
    processed.push_back(index);
}

void createComp(unordered_map<int, set<int>> &revPaths,
                int current, set<int> &newComp, bool *visited, set<int> &added) {
    if (visited[current] || (added.find(current) != added.end())) {
        return;
    }
    visited[current] = true;
    added.insert(current);
    newComp.insert(current);
    for (auto dest : revPaths[current]) {
        createComp(revPaths, dest, newComp, visited, added);
    }
}

bool isWay(unordered_map<int, set<int>> &paths, int from, int to, bool *visited) {
    if (visited[from]) {
        return false;
    }
    visited[from] = true;
    for (auto dest : paths[from]) {
        if (dest == to) {
            return true;
        }
        if (isWay(paths, dest, to, visited)) {
            return true;
        }
    }
    return false;
}

ll countC(ll *coins, set<int> &comp) {
    ll res = 0;
    for (auto node : comp) {
        res += coins[node];
    }
    return res;
}

int main() {
    int n; // numbers of rooms
    int m; // numbers of corridors
    cin >> n >> m;
    ll coins[n];
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    unordered_map<int, set<int>> paths;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        paths[a].insert(b);
    }

    vector<int> processed;
    bool visited[n];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(paths, i, visited, processed);
        }
    }

    unordered_map<int, set<int>> revPaths;
    for (auto path : paths) { // reverse paths
        for (auto dest : path.second) {
            revPaths[dest].insert(path.first);
        }
    }

    set<int> added;
    vector<set<int>> components;
    for (int i = 0; i < n; i++) {
        int current = processed[n - 1 - i];
        if (added.find(current) == added.end()) { // if was not added
            memset(visited, false, sizeof(visited));
            set<int> newComp;
            createComp(revPaths, current, newComp, visited, added);
            components.push_back(newComp);
        }
    }

    //for (auto comp : components) {
    // cout << "Component:" << endl;
    //  for (auto node : comp) {
    //       cout << node << " ";
    //   }
    //    cout << endl;
    //}

    int size = components.size();
    ll bp[size]; // prev node and biggest c
    memset(bp, 0, sizeof(bp));
    bp[0] = countC(coins, components[0]);
    bool proc[size];
    memset(proc, false, sizeof(proc));
    for (int j = 0; j < size; j++) { // for each components
        if (proc[j]) {
            continue;
        }
        proc[j] = true;
        queue<int> q;
        q.push(j);
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            //cout << "looking for paths from " << current << " component" << endl;
            for (int i = current + 1; i < size; i++) {
                memset(visited, false, sizeof(visited));
                if (isWay(paths, *components[current].begin(), *components[i].begin(), visited)) {
                    //cout << "found way to " << i << endl;
                    q.push(i);
                    proc[i] = true;
                    ll thisWayC = bp[current] + countC(coins, components[i]);
                    //cout << "coins count: " << thisWayC << endl;
                    if (thisWayC > bp[i]) {
                        bp[i] = thisWayC;
                    }
                }
            }
        }
    }

    ll res = 0;
    for (int i = 0; i < size; i++) {
        res = max(res, bp[i]);
    }
    cout << res;
    return 0;
}



