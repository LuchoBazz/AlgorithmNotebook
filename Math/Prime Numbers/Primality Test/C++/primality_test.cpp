#include <bits/stdc++.h>
 
using namespace std;

bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            return false;
        }
    }
    return true;
}

bool isPrime(int x) {
    if(x==2 || x==3) return true;
    if(x % 2 == 0 || x % 3 == 0) return false;
    
    for (int d = 3; d * d <= x; d += 2) {
        if (x % d == 0) {
            return false;
        }
    }
    return true;
}

bool isPrime(int number) {
    if(number <= 0) return false;
    else if(number <= 3) return true;

    if(number%2==0 || number%3==0) return false;

    for(int i = 5; i*i <= number; i += 6) {
        if(number%i==0 || number%(i+2)==0) {
            return false;
        }
    }
    return true;
}


int main() {
    int number = 1000000007;
    if(isPrime(number)) {
        cout << "Number is Prime" << endl;
    } else {
        cout << "Number is not prime" << endl;
    }
    return 0;
}