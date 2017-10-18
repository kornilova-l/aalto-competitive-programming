#include <iostream>
#include <cstring>

using namespace std;

int distance(char *x, char *y, int ix, int iy, int *distances[]) {
    if (ix == -1 && iy == -1) return 0;
    if (ix == -1 || iy == -1) return max(ix, iy) + 1;

    if (distances[ix][iy] != -1) {
        return distances[ix][iy];
    }

    distances[ix][iy] = min(min(distance(x, y, ix - 1, iy - 1, distances) + (x[ix] == y[iy] ? 0 : 1),
                                distance(x, y, ix, iy - 1, distances) + 1),
                            distance(x, y, ix - 1, iy, distances) + 1);
    return distances[ix][iy];
}

int main() {
    int MAX = 5000;
    char x[MAX + 1];
    char y[MAX + 1];
    cin.getline(x, MAX);
    cin.getline(y, MAX);
    auto lenX = static_cast<int>(strlen(x));
    auto lenY = static_cast<int>(strlen(y));
    int *distances[lenX];
    for (int i = 0; i < lenX; i++) {
        distances[i] = new int[lenY];
        for (int j = 0; j < lenY; j++) {
            distances[i][j] = -1;
        }
    }
    cout << distance(x, y, lenX - 1, lenY - 1, distances) << endl;
//    for (int i = 0; i < lenX; i++) {
//        for (int j = 0; j < lenY; j++) {
//            cout << distances[i][j] << "\t";
//        }
//        cout << endl;
//    }
    return 0;
}