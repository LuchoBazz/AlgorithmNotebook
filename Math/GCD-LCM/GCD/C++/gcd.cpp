#include <bits/stdc++.h>

using namespace std;

// Euclid's algorithm
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int numberI = 15;
    int numberII = 25;

    cout << gcd(numberI, numberII) << endl;
    //  Greatest Common Divisor: 5
    return 0;
}