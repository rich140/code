#include <iostream>
#include <vector>

using namespace std;

void dfs(vector< vector<int> >& adj, int s, int* visited) {
    if (visited[s]) return;
    visited[s] = true;
    for (auto it = adj[s].begin(); it != adj[s].end(); ++it) {
        dfs(adj, *it, visited);
    }
}
int main() {
    vector<int> adj[4];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);

    dfs(adj, 0, new int[4]); 
    return 0; 
}
