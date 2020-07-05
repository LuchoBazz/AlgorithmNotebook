#include <bits/stdc++.h>
 
using namespace std;

vector<int> sieve(int number) {
    vector<bool> is_prime(number+1, false);
    
    for(int i = 4; i <= number; i += 2) {
        is_prime[i] = true;
    }
    
    for(int prime = 3; prime <= number; prime += 2) {
        if(!is_prime[prime]) {
            for(int j = prime*2; j <= number; j += prime) {
                is_prime[j] = true;
            }
        }
    }

    vector<int> primes;
    for(int i = 2; i <= number; ++i) {
        if(!is_prime[i]) primes.push_back(i);
    }
    return primes;
}

int main() {
    int n = 100;
    
    vector<int> primes = sieve(n);
    // {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}
    return 0;
}