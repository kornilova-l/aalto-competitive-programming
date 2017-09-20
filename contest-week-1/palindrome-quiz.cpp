#include <iostream>

int inc(char *s, int i, int len);

bool isLetter(char &c);

int dec(char *s, int j);

bool check();

char getLower(char &c);

int getLen(char *c, int i);

int main() {
    if (check()) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}

bool check() {
    //std::string s;
    //std::getline (std::cin,s);
    char s[1000000];
    std::cin.getline(s, 1000000);
    int len = getLen(s, 1000000);
    //int len = (int) s.length();
    int j = len - 1;
    int i = 0;
    i = inc(s, i, len);
    j = dec(s, j);
    bool isChecked = false;
    for (; i <= j;) {
        if (getLower(s[i]) != getLower(s[j])) {
            return false;
        }
        isChecked = true;
        i++;
        j--;
        i = inc(s, i, len);
        j = dec(s, j);
    }
    return isChecked;
}

int getLen(char *c, int n) {
    for (int i = 0; i < n; i++) {
        if (c[i] == 0) {
            return i;
        }
    }
    return n;
}

char getLower(char &c) {
    if (c <= 'Z' && c >= 'A') {
        return c - ('Z' - 'z');
    }
    return c;
}

int inc(char *s, int i, int len) {
    while (i < len - 1 && !isLetter(s[i])) {
        i++;
    }
    return i;
}

int dec(char *s, int j) {
    while (j > 0 && !isLetter(s[j])) {
        j--;
    }
    return j;
}

bool isLetter(char &c) {
    return (c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a');
}

