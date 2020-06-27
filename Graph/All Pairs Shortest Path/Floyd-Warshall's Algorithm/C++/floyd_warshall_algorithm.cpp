#include <bits/stdc++.h>

using namespace std;

const int oo  = int(1e9 + 20);

// --------------------------------------------------------------

class FloydWarshall {
    vector<vector<int>> graph;
public:

    FloydWarshall(vector<vector<int>> matrix) : graph(matrix) {}

    vector<vector<int>> build() {
        int n = graph.size();

        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
        return graph;
    }

    string toString() {
        int n = graph.size();
        string output = "";
        for(int i = 0; i < n; ++i) {
            output += to_string(i);
            output.push_back(' ');
            output.push_back('|');
            for(int j = 0; j < n; ++j) {
                if(graph[i][j] == oo) {
                    output += "oo";
                } else {
                    output += to_string(graph[i][j]);    
                }
                
                output.push_back(' ');
            }
            output.push_back('\n');
        }
        return output;
    }
};

int main() {
    vector<vector<int>> graph = {
        {oo, 4, oo, oo, oo, oo, oo, 8, oo },
        {4, oo, 8, oo, oo, oo, oo, 11, oo },
        {oo, 8, oo, 7, oo, 4, oo, oo, 2 },
        {oo, oo, 7, oo, 9, 14, oo, oo, oo },
        {oo, oo, oo, 9, oo, 10, oo, oo, oo },
        {oo, oo, 4, 14, 10, oo, 2, oo, oo },
        {oo, oo, oo, oo, oo, 2, oo, 1, 6 },
        {8, 11, oo, oo, oo, oo, 1, oo, 7 },
        {oo, oo, 2, oo, oo, oo, 6, 7, oo }
    };

    FloydWarshall fw(graph);

    fw.build();

    cout << fw.toString() << endl;
    // 0 |8 4 12 19 21 11 9 8 14 
    // 1 |4 8 8 15 22 12 12 11 10 
    // 2 |12 8 4 7 14 4 6 7 2 
    // 3 |19 15 7 14 9 11 13 14 9 
    // 4 |21 22 14 9 18 10 12 13 16 
    // 5 |11 12 4 11 10 4 2 3 6 
    // 6 |9 12 6 13 12 2 2 1 6 
    // 7 |8 11 7 14 13 3 1 2 7 
    // 8 |14 10 2 9 16 6 6 7 4 

    return 0;
}