#ifndef __ASSN03_H__
#define __ASSN03_H__

#include <iostream>
using namespace  std;

int foo(int x) {
    x += 10;
    return x+5;
}

int bar(int& x) {
    x = 2720;
    return x-100;
}

int main() {


    int v1 {1730};
    int v2 {42};
    cout << foo(v1) << endl;
    cout << v1 << endl;
    cout << foo(v2) << endl;
    cout << v2 << endl;

    cout << bar(v1) << endl;
    cout << v1 << endl;
    cout << bar(v2) << endl;
    cout << v2 << endl;

    int x{1000};
    int& y{x};

    x+= 100;
    cout << x << endl;
    cout << y << endl;

    y = 2020;
    cout << x << endl;
    cout << y << endl;
return 0;
}


#endif // __ASSN03_H__