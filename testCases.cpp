#include <iostream>

using namespace std;

int main() {
    for (int i = 0; i < 5; i++) {
        cout << "got here" << endl;
        if (i == 1) {
            cout << "oops" << endl;
        } // for
        return 0;
    } // main