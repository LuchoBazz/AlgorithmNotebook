// Made by Luis Miguel Baez
// es.luismiguelbaez@gmail.com

#include <bits/stdc++.h>
 
using namespace std;

class SCC_Tarjan {
    vector<vector<int>> adj,scc;
    int vertex;
    int count;
    vector<bool> onstack;
    stack<int> st;
public:
    vector<int> disc,low;

    SCC_Tarjan(int vertex) : vertex(vertex) {
        adj.resize(vertex, vector<int>{});
        disc.resize(vertex,-1);
        low.resize(vertex);
        onstack.resize(vertex, false);
        count = 0;
    }
    
    void addEdge(int from, int to) {
        adj[from].push_back(to);
    }
    
    void tarjan(int node){
        disc[node] = count;
        low[node] = count++;

        st.push(node);
        onstack[node] = true;

        for(int neighbour: adj[node]){
            if(disc[neighbour] == -1){
                tarjan(neighbour);
                low[node] = min(low[node],low[neighbour]);
            } else if(onstack[neighbour]) {
                low[node]=min(low[node], disc[neighbour]);
            }
        }

        if(disc[node] == low[node]){
            vector<int> scctem;
            int v;
            do {
                v = st.top();
                st.pop();
                onstack[v]=false;
                cout << v << " ";
                scctem.push_back(v);
            } while(node!=v);

            scc.push_back(scctem);
            cout << endl;
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n = 8;
    
    SCC_Tarjan scc(n);
    
    scc.addEdge(0, 2);
    scc.addEdge(1, 0);
    scc.addEdge(2, 1);
    scc.addEdge(2, 3);
    scc.addEdge(3, 4);
    scc.addEdge(4, 5);
    scc.addEdge(5, 6);
    scc.addEdge(6, 7);
    scc.addEdge(7, 4);
    
    for(int i = 0; i < n; ++i) {
        if(scc.disc[i] == -1) {
            scc.tarjan(i);
        }
    }
    
    // Out:
    // 0 1 2
    // 3
    // 4 7 6 5

    return 0;
}
