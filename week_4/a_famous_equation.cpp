#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <tuple>

#define ll long long
using namespace std;

vector<int> reverse(vector<int> &a) {
    int s = a.size();
    vector<int> newV;
    for (int i = 0; i < s; i++) {
        newV.push_back(a[s - 1 - i]);
    }
    return newV;
}

set<tuple<char, char, char>> do_iteration(set<tuple<char, char, char>> &prev_pairs, char a, char b, char c, ll &res) {
    set<tuple<char, char, char>> s;
    for (tuple<char, char, char> a_b_c : prev_pairs) {
        char add = (get<0>(a_b_c) + get<1>(a_b_c) == get<2>(a_b_c)) ? 0 : 1;
        if (c == -1) { // if res is undefined
            if (a == -1 && b == -1) {
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        s.insert({i, j, (i + j + add) % 10});
                    }
                }
            } else if (a != -1 && b == -1) { // if a is defined
                for (int i = 0; i < 10; i++) {
                    s.insert({a, i, (a + i + add) % 10});
                }
            } else if (a == -1 && b != -1) { // if b is defined
                for (int i = 0; i < 10; i++) {
                    s.insert({i, b, (b + i + add) % 10});
                }
            } else { // both defined
                s.insert({a, b, (a + b + add) % 10});
            }
        } else { // res is defined
            if (a == -1 && b == -1) { // if both undefined
                for (int i = 0; i < 10; i++) {
                    s.insert({(c + 10 - add - i) % 10, i, c});
                }
            } else if (a != -1 && b == -1) { // a is defined
                s.insert({a, (c + 10 - add - a) % 10, c});
            } else { // all is defined
                if ((a + b + add) % 10 == c) {
                    s.insert({a, b, c});
                }
            }
        }


        if (a != -1 && b != -1) { // both defined
            if (c != -1) { // res defined
                if (a + b + add == c) {
                    s.insert({a, b});
                }
            } else { // res undefined
                s.insert({a, b}); // does not matter
            }
        } else {
            if (a == -1 && b != -1) { // a is undefined
                if (c != -1) {

                } else { // c is undefined

                }
            }
        }
    }
    return move(s);
};


int main() {
    string s;
    ll case_count = 1;
    while (cin >> s) {
        vector<int> a;
        vector<int> b;
        vector<int> c;
        char ch;
        int index = 0;
        ch = s[index++];
        while (ch != '+') {
            if (ch == '?') {
                a.push_back(-1);
            } else {
                a.push_back(ch - '0');
            }
            ch = s[index++];
        }
        ch = s[index++];
        while (ch != '=') {
            if (ch == '?') {
                b.push_back(-1);
            } else {
                b.push_back(ch - '0');
            }
            ch = s[index++];
        }
        ch = s[index++];
        while (index != s.length() + 1) {
            if (ch == '?') {
                c.push_back(-1);
            } else {
                c.push_back(ch - '0');
            }
            ch = s[index++];
        }
        a = reverse(a);
        b = reverse(b);
        c = reverse(c);
        int max_len = c.size();
        for (int i = a.size(); i < max_len; i++) {
            a.push_back(0);
        }
        for (int i = b.size(); i < max_len; i++) {
            b.push_back(0);
        }
        unordered_map<pair<int, int>, set<pair<int, int>>> m;
        set<pair<int, int>> current_set;
        int curr_a = a[0];
        int curr_b = b[0];
        int curr_c = c[0];
        if (curr_a != -1 && curr_b != -1) {
            current_set.insert({curr_a, curr_b});
        } else {
            if (curr_c == -1) {
                if (curr_a == -1 && curr_b != -1) {
                    for (int j = 0; j < 10; j++) {
                        current_set.insert({j, curr_b});
                    }
                } else if (curr_a == -1 && curr_b != -1)

            } else {
                if (curr_a == -1 && curr_b != -1) current_set.insert({curr_c - curr_b, curr_b});
                else if (curr_a != -1 && curr_b == -1) current_set.insert({curr_a, curr_c - curr_a});
                else {
                    for (int j = 0; j <= curr_c; j++) {
                        current_set.insert({j, curr_c - j});
                    }
                }
            }
        }

        for (int i = 0; i < max_len; i++) {
            int res = c[i];
            if (res == -1) { // if '?'

            }
        }
//        cout << "Case " << case_count << ": " << b_count + s.size() << endl;
//        case_count++;
    }
    return 0;
}
