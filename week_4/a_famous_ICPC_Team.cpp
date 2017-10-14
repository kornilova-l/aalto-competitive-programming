#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

int main() {
    vector<ll> sizes;
    for (int i = 0; i < 4; i++) {
        sizes.push_back(0);
    }
    int i = 1;
    while (cin >> sizes[0] >> sizes[1] >> sizes[2] >> sizes[3]) {
        ll min_size = 0;
        sort(sizes.begin(), sizes.end(), greater<ll>());
        cout << "Case " << i << ": " << sizes[0] + sizes[1] << endl;
        i++;
//        min_size = sizes[0] + sizes[1];
//        ll left = sizes[0] - sizes[1];
//        if (left >= sizes[2]) {
//            cout << min_size << endl;
//            continue;
//        } else {
////            min_size = sizes[1] + sizes[2];
//            left = sizes[0] - sizes[2];
//            if (left > sizes[3]) {
//                cout << max(min_size, sizes[2] + sizes[3]) << endl;
//                continue;
//            } else {
//                cout << min_size << endl;
//                continue;
//            }
//        }
    }
    return 0;
}
