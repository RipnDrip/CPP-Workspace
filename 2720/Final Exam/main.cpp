#include <iostream>

using namespace std;

void Func( int n) {
    if ( n > 0) {
        Func(n/5);
        cout << n % 5 << endl;
    }
}

int main() {

    int test = 73;

    Func(test);
}