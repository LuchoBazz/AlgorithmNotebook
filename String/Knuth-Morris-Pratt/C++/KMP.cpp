// Made by Luis Miguel Baez
// lmbaeza@unal.edu.co

#include <bits/stdc++.h>
 
using namespace std;

void LPS(string pat, vector<int> &lps) { 
    int M = pat.size();
    int len = 0; 
    int i = 1; 
    lps[0] = 0; // lps[0] siempre es 0

    // Calcular lps[i] for i = 1 to M-1 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } else { 
            if (len != 0) { 
                len = lps[len - 1]; 
            } else { 
                lps[i] = len; 
                i++; 
            } 
        } 
    }
}

vector<int> search(string txt, string pat) {
    vector<int> output;

    int N = txt.size();
    int M = pat.size();

    if(M > N) return output;

    // Longest Prefix Suffix
    // int lps[] = new int[M];
    vector<int> lps(M);
    
    int j = 0; // index for pat[] 

    // Calcular el array con los datos del 'Longest Prefix Suffix'
    LPS(pat, lps); 

    int i = 0; // index for txt[] 

    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        }

        if (j == M) {
            // Found pattern at index (i-j)
            output.push_back(i-j);
            j = lps[j - 1]; 
        } else if (i < N && pat[j] != txt[i]) { 
            if (j != 0) {
                j = lps[j - 1]; 
            } else {
                i = i + 1; 
            }
        } 
    }
    return output;
} 

int main() {
    
    string txt = "ABABDABACDABABCABAB"; 
    string pat = "ABAB"; 
    vector<int> ans = search(txt, pat);

    for(int index: ans) {
        cout << "Found pattern at index: " << index << endl;
    }
    
    // Out[1]:
    // Found pattern at index: 0
    // Found pattern at index: 10
    // Found pattern at index: 15
    
    return 0;
}