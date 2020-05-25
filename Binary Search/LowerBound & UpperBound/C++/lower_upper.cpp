#include <bits/stdc++.h>
 
using namespace std;


int lowerBound(vector<int> &values, int target) {
    int n = values.size();
    int low=0, high=n-1, mid;
    
    while(low <= high) {
        mid = (low + high) / 2;
        
        if(values[mid] < target) {
          low = mid + 1;  
        } else {
            high = mid - 1;
        }
    }
    
    return low;
}

int upperBound(vector<int> &values, int target) {
    int n = values.size();
    int low=0, high=n-1, mid;
    
    while(low <= high) {
        mid = (low + high) / 2;
        
        if(values[mid] <= target) {
          low = mid + 1;  
        } else {
            high = mid - 1;
        }
    }
    
    return low;
}


int main() {
    // indexes:    0  1  2  3  4  5  6  7  8  9   10
    vector<int> v {1, 2, 3, 3, 3, 3, 4, 4, 7, 10, 12};
    
    int target = 1;
    
    int lower = lowerBound(v, target);
    int upper = upperBound(v, target);
    
    cout << "Lower: " << lower  << '\n';
    cout << "Upper: " << upper << '\n'; 

    // Target: 1

    // Lower: 0
    // Upper: 1
    
    return 0;
}