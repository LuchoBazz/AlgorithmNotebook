#include <bits/stdc++.h>

using namespace std;

bool isPowerOfN(int number, int N) { 
    if(number == 0 || (number!=1 && N == 0)) return false; 
    else if(N == 1) return true;
    
    while(number != 1) {  
        if(number % N != 0)  {
            return false; 
        }
        number = number / N;  
    } 
    return true; 
} 

int sum_multiple(int number, int N) {
    // Number of multiples 
    int m = N / number;

    // sum of first m natural numbers 
    int sum = m*(m + 1) / 2;

    // sum of multiples
    return number*sum;
}

int main() {
    // 64 it's power of N: True
    cout << isPowerOfN(64, 2) << endl;

    // sum_multiple(3, 12) = 3+6+9+12 = 30
    cout << sum_multiple(3, 12) << endl;
    
    return 0;
}