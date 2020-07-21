#include <bits/stdc++.h>
using namespace std;

template<class T>
vector<T> divisors(T number) {
    vector<T> solutions;
    // 1 <= i <= sqrt(number)
    for (T i = 1; i <= sqrt(number); ++i) {
        if (number % i == 0) { // if i is divisor of number
            if (number/i == i) {
                // if i*i == number
                solutions.push_back(i);
            } else {
                // x=i, y=number/i
                // if x*y==number
                solutions.push_back(i);
                solutions.push_back(number/i);
            }
        }
    }
    return solutions;
} 

int main() {

    int number = 100;
    
    vector<int> ans = divisors<int>(number);
    
    // ans:
    // {1, 100, 2, 50, 4, 25, 5, 20, 10}
    
    return 0;
}