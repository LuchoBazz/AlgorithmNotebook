#include <bits/stdc++.h>
 
using namespace std;

const int n = 3;
vector<bool> bits(n, false);

void printBits() {
	for(int i = 0; i < n; ++i) {
		cout << (bits[i])?1:0;
	}
	cout << endl;
}

void backtracking(int i) {
	if(i == n) {
		printBits();
	} else {
		bits[i] = true;
		backtracking(i+1);
		bits[i] = false;
		backtracking(i+1);
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int start = 0;
	backtracking(start);
    
    // Out:
    // 111
    // 110
    // 101
    // 100
    // 011
    // 010
    // 001
    // 000

    return 0;
}
