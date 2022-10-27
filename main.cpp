
#include "btree.hpp"

#include <iostream>

using namespace std;

int main() {
    string test;
    cin >> test;
    cout << test << endl;
    btree T(cin);
    T.print(cout);

    for (int i = -4; i < 64; i++) {
        if (T.search(i)) {
            cout << i << ' ';
        }
    }
    cout << endl;

    T.insert(52);

    T.print(cout);

    cout << "hi" << endl;
} // main
