#include <iostream>

using namespace std;


int main() {
    int n; // number of days
    int q; // number of queries
    cin >> n >> q;
    int arr[n + 1];
    arr[0] = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr[i + 1] = arr[i] + a;
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << arr[b] - arr[a - 1] << endl;
    }
    return 0;
}