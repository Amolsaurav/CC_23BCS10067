#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<int>& visited, int node) {
    visited[node] = 1;
    for (auto it : adj[node]) {
        if (!visited[it]) {
            dfs(adj, visited, it);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> visited(n + 1, 0);
    vector<int> comp;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            comp.push_back(i);
            dfs(adj, visited, i);
        }
    }

    cout <<"Total number of Components : "<< comp.size() - 1 << endl;

    for (int i = 0; i + 1 < comp.size(); i++) {
        cout << comp[i] << " " << comp[i + 1] << endl;
    }

    return 0;
}
