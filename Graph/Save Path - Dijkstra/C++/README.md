# Dijkstra's Algorithm - C++

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación](#implementación)
* [Complejidad](#complejidad)

## Ilustración

<img alt="Dijkstra's Algorithm" src="https://upload.wikimedia.org/wikipedia/commons/7/74/Boruvka%27s-algorithm-example.gif" width="300">

_Tomado de:_ [Wikipedia](https://commons.wikimedia.org/wiki/File:Boruvka's-algorithm-example.gif)

<img alt="Algoritmo de Dijkstra" src="https://i.ibb.co/ydC721z/Dijkstra.png" width="500">

## Implementación

```c++
#include <bits/stdc++.h>
 
using namespace std;
 
const int oo = INT_MAX;
 
struct Node {
    int to;
    int dist;
    
    bool operator>(const Node other) const {
        return dist > other.dist;
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n , m;
    
    cin >> n >> m;
    
    vector<vector<Node>> adj(n+1);
    vector<int> distances(n+1, oo);
    vector<int> prev(n+1, -1);
    
    int x, y;
    int w;
    
    for(int i = 0; i < m; ++i) {
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    
    
    priority_queue<Node, vector<Node>, greater<Node>> Q;
    
    int start = 1;
    int end = n;
    
    int node;
    int newDist;
    
    Q.push({start, 0});
    distances[start] = 0;
    
    while(Q.size() > 0) {
        node = Q.top().to;Q.pop();
        
        for(Node neighboor: adj[node]) {
            newDist = distances[node] + neighboor.dist;
            
            if(newDist < distances[neighboor.to]) {
                distances[neighboor.to] = newDist;
                Q.push({neighboor.to, newDist});
                prev[neighboor.to] = node;
            }
        }
    }
    
    
    if(distances[end] == oo) {
        cout << "No path found\n";
    } else {
        vector<int> path;
        
        for(int index = end; index != -1; index = prev[index]) {
            path.push_back(index);
        }
        
        for(int i = path.size()-1; i >= 0; i--) {
            cout << path[i] << " ";
        }
    }
    
    return 0;
}
```


## Complejidad


![Complejidad Dijkstra](https://i.ibb.co/ZMVWL3q/O-E-V-log-V.gif)

Donde:

* ![Edge](https://i.ibb.co/tmtnPJW/O-E.gif) Es el numero de Aristas

* ![Vertex](https://i.ibb.co/hWMhHhC/OV.gif) Es el numero de Vertices