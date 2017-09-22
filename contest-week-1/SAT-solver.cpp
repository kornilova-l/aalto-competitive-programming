#include <iostream>
#include <unordered_map>
#include <set>
#include <cstring>
#include <queue>

using namespace std;

void updateFlow(unordered_map<int, set<pair<int, int>>> graph,
                unordered_map<int, int> previous,
                int sink) {
    int next = sink;
    int prev = previous[next];
    while (prev != 0) {
        for (auto path : graph[prev]) {
            if (path.first == next) {
                path.second = 0;
            }
        }
        for (auto path : graph[next]) {
            if (path.first == prev) {
                path.second = 1;
            }
        }
        next = prev;
        prev = previous[prev];
    }
}

int increaseMaxFlow(unordered_map<int, set<pair<int, int>>> graph, int sink) {
    bool visited[sink + 1];
    memset(visited, false, sizeof(visited));
    queue<int> q;
    unordered_map<int, int> previous; // previous node and it's max flow
    previous[sink] = 0;
    previous[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        visited[current] = true;
        set<pair<int, int>> paths = graph[current];
        for (auto path : paths) {
            int next = path.first;
            if (!visited[next] && path.second > 0) {
                previous[next] = current;
                q.push(path.first);
            }
        }
    }
    int flow = previous[sink] == 0 ? 0 : 1;
    if (flow == 0) { // if sink was not reached
        return 0;
    }
    updateFlow(graph, previous, sink);
    return flow;
}

void printGraph(unordered_map<int, set<pair<int, int>>> graph) {
    for (auto node : graph) {
        for (auto path : node.second) {
            cout << node.first << " -> " << path.first << " w: " << path.second << endl;
        }
    }
}

int main() {
    int n; // number of variables
    int m; // number of clauses
    char ch;
    for (int i = 0; i < 4; i++) {
        cin >> ch;
    }
    cin >> n >> m;
    unordered_map<int, set<pair<int, int>>> graph; // a -> b (weight c)
    // graph[0] is source
    // graph[1, m] is clauses
    // graph[m + 1, m + n] is variables
    // graph[m + n + 1] is sink
    int a, b, c; // variables
    int zero;
    for (int i = 0; i < m; i++) { // for each clause
        cin >> a >> b >> c >> zero;
        a = abs(a);
        b = abs(b);
        c = abs(c);
        graph[0].insert({i + 1, 1});
        graph[i + 1].insert({0, 0});
        graph[i + 1].insert({a + m, 1});
        graph[a + m].insert({i + 1, 0});
        graph[i + 1].insert({b + m, 1});
        graph[b + m].insert({i + 1, 0});
        graph[i + 1].insert({c + m, 1});
        graph[c + m].insert({i + 1, 0});
    }
    int sink = m + n + 1;
    for (int i = m + 1; i < sink; i++) { // connect all variables to sink
        graph[i].insert({sink, 1});
        graph[sink].insert({i, 0});
    }
    int flow = 0;
    printGraph(graph);
    while (flow += increaseMaxFlow(graph, n + m + 1)) {

    }
    if (flow == m) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
