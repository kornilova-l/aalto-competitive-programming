#include <iostream>
#include <cmath>

#define big 1000000007
#define ten9 100000000000
#define ull unsigned long long

using namespace std;

void multiply(ull m1[2][2], ull m2[2][2]) {
    ull i00 = (m1[0][0] * m2[0][0] + m1[0][1] * m2[0][1]) % ten9;
    ull i01 = (m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1]) % ten9;
    ull i10 = (m1[1][0] * m2[0][0] + m1[1][1] * m2[0][1]) % ten9;
    ull i11 = (m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1]) % ten9;
    m1[0][0] = i00;
    m1[0][1] = i01;
    m1[1][0] = i10;
    m1[1][1] = i11;
}

void toPower(ull m[2][2], ull power, ull m2[2][2]) {
    m2[0][0] = m[0][0];
    m2[0][1] = m[0][1];
    m2[1][0] = m[1][0];
    m2[1][1] = m[1][1];
    for (ull i = 0; i < power; i++) {
        multiply(m2, m2);
    }
}

void doFib(ull f1, ull f2, ull n) {
    if (n == 1) {
        cout << f1;
        return;
    }
    if (n == 2) {
        cout << f2;
        return;
    }
    n -= 2;
    ull power = (ull) floor(log2(n));
    ull rest = n - (ull) pow(2, power);
    ull bm[2][2];
    bm[0][0] = 0;
    bm[1][0] = 1;
    bm[0][1] = 1;
    bm[1][1] = 1;
    ull matrix[2][2];
    toPower(bm, power, matrix);
    if (rest == 0) {
        power = 0;
    } else {
        power = (ull) floor(log2(rest));
        if (power != 0) {
            rest -= (ull) pow(2, power);
        }
    }
    while (power != 0) {
        ull newM[2][2];
        toPower(bm, power, newM);
        multiply(matrix, newM);
        if (rest == 0) {
            power = 0;
        } else {
            power = (ull) floor(log2(rest));
            if (power != 0) {
                rest -= (ull) pow(2, power);
            }
        }
    }
    for (ull i = 0; i < rest; i++) {
        multiply(matrix, bm);
    }
    cout << ((f1 * matrix[0][1]) % big + (f2 * matrix[1][1]) % big) % big;
}

int main() {
    ull f1;
    ull f2;
    ull n;
    cin >> f1 >> f2 >> n;
    doFib(f1, f2, n);
//    for (ull i = 1; i <= n; i++) {
//        doFib(f1, f2, i);
//        cout << endl;
//    }
}