#include <bits/stdc++.h>

using namespace std;

// Euclid's algorithm
int gcd (int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b) {  
    return (a*b)/gcd(a, b);  
}

int main() {
    int numberI = 15;
    int numberII = 20;

    cout << lcm(numberI, numberII) << endl;
    // Least Common Multiple: 75

    return 0;
}