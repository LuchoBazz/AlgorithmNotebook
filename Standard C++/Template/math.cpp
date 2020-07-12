#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
//---------------------------------------------------

#define PI   3.141592653589793238462643383279502884L // (2*acos(0.0))
#define eps  1e-9
#define gcd  __gcd

template<typename T>
T lcm(T x, T y ) {return x*(y/gcd(x,y));}

// Primality Test
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

// Prime Factors
vector<int> primeFactors(int number) {
    vector<int> factors;
    while (number % 2 == 0) {
        factors.push_back(2);
        number = number / 2;
    }
    for (int i = 3; i*i <= number; i += 2) {
        while (number % i == 0) {
            factors.push_back(i);
            number = number / i;
        }
    }
    if (number > 2) factors.push_back(number);
    return factors;
}

// Sieve of Eratosthenes
vector<int> sieve(int number) {
    vector<bool> is_prime(number+1, false);
    for(int i = 4; i <= number; i += 2) is_prime[i] = true;
    for(int prime = 3; prime <= number; prime += 2) {
        if(!is_prime[prime]) {
            for(int j = prime*2; j <= number; j += prime) is_prime[j] = true;
        }
    }
    vector<int> primes;
    for(int i = 2; i <= number; ++i) {
        if(!is_prime[i]) primes.push_back(i);
    }
    return primes;
}

// ToolBox

// It's Power of N
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

// Sum of Multiples of a number up to N
// sum_multiple(3, 12) = 3+6+9+12 = 30
int sum_multiple(int number, int N) {
    int m = N / number;
    int sum = m*(m + 1) / 2;
    return number*sum;
}