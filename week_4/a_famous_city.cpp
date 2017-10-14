#include <iostream>
#include <set>
#include <stack>

#define ll long long

using namespace std;

int main() {
    int n;
    ll case_count = 1;
    while(cin >> n) {
        stack<ll> s;
        int b_count = 0;
        ll h;
        for (int i = 0; i < n; i++) {
            cin >> h;
            if (s.empty() && h != 0) {
                s.push(h);
                continue;
            }
            if (h == 0) {
                b_count += s.size();
                while(!s.empty()) {
                    s.pop();
                }
            } else {
                if(h == s.top()) {
                    continue;
                } else {
                    if (h > s.top()) {
                        s.push(h);
                    } else {
                        while (!s.empty()) {
                            s.pop();
                            b_count++;
                            if (s.empty()) {
                                s.push(h);
                                break;
                            }
                            ll last_h = s.top();
                            if (last_h < h) {
                                s.push(h);
                                break;
                            }
                            if (last_h == h) {
                                break;
                            }
                        }
                    }
                }
            }
        }
        cout << "Case " << case_count << ": " << b_count + s.size() << endl;
        case_count++;
    }
    return 0;
}
