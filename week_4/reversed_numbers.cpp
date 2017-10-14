#include <iostream>

int reverse(int a);

using namespace std;

int main() {
//    cout << reverse(23) << endl;
//    cout << reverse(230) << endl;
//    cout << reverse(2300) << endl;
//    cout << reverse(203) << endl;
//    cout << reverse(233) << endl;
    int a, b;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        int revA = reverse(a);
        int revB = reverse(b);
        cout << reverse(revA + revB) << endl;
    }
    return 0;
}

int reverse(int a) {
    int rev = 0;
    bool first_zero = true;
    while (a != 0) {
        int digit = a % 10;
        a = a / 10;
        if (first_zero) {
            if (digit != 0) {
                first_zero = false;
                rev = rev * 10 + digit;
            }
        } else {
            rev = rev * 10 + digit;
        }
    }
    return rev;
}