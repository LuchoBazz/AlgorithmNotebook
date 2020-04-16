// By Luis Miguel Baez - en.luismiguelbaez@gmail.com

#include <bits/stdc++.h>

using namespace std;

#define oo INT_MAX

struct Node {
    int to;
    int dist;

    bool operator>(const Node& node) const {
        return dist > node.dist;
    }

};

int main() {
    int n = 5;

    int A = 0, B = 1, C = 2, D = 3, E = 4;

    int start = A;

    vector<vector<Node>> adj(n);

    adj[A].push_back({B, 6});adj[B].push_back({A, 6});
    adj[A].push_back({D, 1});adj[D].push_back({A, 1});
    adj[B].push_back({D, 2});adj[D].push_back({B, 2});
    adj[E].push_back({D, 1});adj[D].push_back({E, 1});
    adj[B].push_back({E, 2});adj[E].push_back({B, 2});
    adj[B].push_back({C, 5});adj[C].push_back({B, 5});
    adj[C].push_back({E, 5});adj[E].push_back({C, 5});

    priority_queue<Node, vector<Node>, greater<Node>> Q;

    vector<int> distances(n, oo);

    distances[start] = 0;

    //       to   dist
    Q.push({start, 0});

    while (!Q.empty()) {
        int node = Q.top().to; Q.pop();

        for (Node neighboor: adj[node]) {
            int newDist = distances[node] + neighboor.dist;

            if (newDist < distances[neighboor.to]) {
                Q.push({neighboor.to, newDist});
                distances[neighboor.to] = newDist;
            }
        }
    }


    for(int i = 0; i < n; ++i) {
        cout<<"To: ["<<i<<"] Distance: ["<<DIST[i]<<"]"<<endl;
    }

    // To: [A] Distance: [0]
    // To: [B] Distance: [3]
    // To: [C] Distance: [7]
    // To: [D] Distance: [1]
    // To: [E] Distance: [2]

    return 0;
}