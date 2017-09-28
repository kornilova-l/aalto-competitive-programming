#include <iostream>
#include <string.h>

#define ll long long

using namespace std;

ll best(int *cost, int i, ll b[][2], bool *ready) {
    if (ready[i]) {
        return min(b[i][0], b[i][2]);
    }
    ll res;
    if (i == 0) {
        res = cost[0];
        b[i][0] = b[i][1] = res;
    } else if (i == 1) {
        res = min(cost[0], cost[1]);
        b[1][0] = cost[1];
        b[1][1] = cost[0];
    } else {
        best(cost, i - 1, b, ready);
        best(cost, i - 2, b, ready);
        b[i][0] = min(min(b[i - 1][0], b[i - 1][1]), b[i - 2][1]) + cost[i];
        b[i][1] = b[i - 1][0];
        res = min(b[i][0], b[i][1]);
    }
    ready[i] = true;
    return res;
}

int main() {
    int n;
    cin >> n;
    int cost[n];
    ll b[n][2]; // using self value or using value of neighbour
    bool ready[n];
    memset(ready, false, sizeof(ready));
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    cout << best(cost, n - 1, b, ready);
    return 0;
}