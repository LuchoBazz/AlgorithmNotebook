#include <bits/stdc++.h>
 
using namespace std;

class ArticulationPoints {
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> low;
    vector<int> order;
    vector<bool> points;
    int counter = 0;
    int vertex;
public:
    
    ArticulationPoints(int vertex) : vertex(vertex) {
        adj.resize(vertex);
        visited.resize(vertex, false);
        low.resize(vertex, 0);
        order.resize(vertex, 0);
        points.resize(vertex, false);
    }
    
    void addEdge(int left, int right) {
        adj[left].push_back(right);
        adj[right].push_back(left);
    }

    void dfs(int node, int parent = -1) {
        visited[node] = true;
        low[node] = order[node] = ++counter;

        int children = 0;

        for(int &neighbour: adj[node]) {

            if(!visited[neighbour]) {
                children++;

                dfs(neighbour, node);

                low[node] = min(low[node], low[neighbour]);
                
                // Conditions #1
                if(parent != -1 && order[node] <= low[neighbour]) {
                    points[node] = true;
                }
            } else {
                low[node] = min(low[node], order[neighbour]);
            }
        }
        
        // Conditions #2
        if(parent == -1 && children > 1) {
            points[node] = true;
        }
    }
    
    vector<int> build() {
        for(int node = 0; node < vertex; ++node) {
            if(!visited[node]) {
                dfs(node);
            }
        }
        
        vector<int> output;
        
        for(int node = 0; node < vertex; ++node) {
            if(points[node]) {
                output.push_back(node);
            }
        }
        return output;
    }
};

int main() {
    
    int vertex, edges, x, y;
    
    cin >> vertex >> edges;
    
    ArticulationPoints aps(vertex);
    
    for(int i = 0; i < edges; ++i) {
        cin >> x >> y;
        aps.addEdge(x, y);
    }

    aps.addEdge(0, 1);
    aps.addEdge(0, 2);
    aps.addEdge(1, 2);
    aps.addEdge(2, 3);
    aps.addEdge(3, 4);
    aps.addEdge(2, 5);
    aps.addEdge(5, 6);
    aps.addEdge(6, 7);
    aps.addEdge(7, 8);
    aps.addEdge(8, 5);
    
    vector<int> points = aps.build();
    
    for(int i = 0; i < points.size(); ++i) {
        cout << points[i] << endl;
    }
    
    return 0;
}