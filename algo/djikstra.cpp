#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Edge {
    public:
        Edge(int srcid, int dstid, int w): srcid(srcid), dstid(dstid), w(w) {};
        int srcid;
        int dstid;
        int w;
};

class Node {
    public:
        Node(int id, vector<Edge> edges): id(id), edges(edges) {};
        int id;
        vector<Edge> edges; 
};

class Graph {
    public:
        Graph(vector<Node> nodes): nodes(nodes) {};
        vector<Node> nodes;
};

// Compare operator for a min-heap sorted by second element in pair
struct compare {
    bool operator() (pair<int, int> const& a, pair<int, int> const& b) {
        return a.second > b.second;
    }
};

// Outputs the path to a node as a string
string getPath(vector<int>& backptr, int v) {
    int n = v;
    string path = "";
    while (backptr[n] != n) {
       path = " -> " + to_string(n) + path; 
       n = backptr[n];
    }
    path = to_string(n) + path;
    return path;
}

/* 
Finds the shortest distance between two nodes in a graph and returns its path
v1 and v2 are the indices of the two nodes in graph g
*/
pair<int, string> djikstra(Graph g, int v1, int v2) {
    unordered_set<int> S;
    priority_queue<pair<int, int>, vector<pair<int, int> >, compare> F;
    F.push(make_pair(g.nodes[v1].id, 0));
    vector<int> distance(g.nodes.size(), 99999);
    vector<int> backptr(g.nodes.size(), -1);
    distance[v1] = 0;
    backptr[v1] = v1;
    /* Loop invariants
    (1) For a node s in settled set S, a shortest path from v1 to s
        exists that contains only settled nodes. Its distance is
        distance[s] and backpointer is backptr[s]
    (2) For each node f in frontier set F, a path from v1 to f exists
        that only contains settled nodes execept for f. Its distance is
        distance[f] and backpointer is backptr[f]
    (3) All edges leaving from nodes in S lead to nodes in F 
    */
    while (!F.empty()) {
        Node f = g.nodes[F.top().first];
        F.pop();
        S.insert(f.id);
        if (f.id == v2) {
            return make_pair(distance[v2], getPath(backptr, v2));
        }
        for (Edge e : f.edges) {
            if (!S.count(e.dstid)) {
                distance[e.dstid] = distance[e.srcid] + e.w;
                F.push(make_pair(e.dstid, distance[e.dstid]));
                backptr[e.dstid] = e.srcid;
            } else if (distance[e.srcid] + e.w < distance[e.dstid]) {
                distance[e.dstid] = distance[e.srcid] + e.w;
                backptr[e.dstid] = e.srcid;
            } else {}
        }        
    }
    return make_pair(-1, "Path not found");
}

int main() {
    // Define graph
    Graph g({Node(0, {Edge(0,1,5), Edge(0,3,9), Edge(0,4,1)}),
            Node(1, {Edge(1,0,5), Edge(1,2,2)}),
            Node(2, {Edge(2,1,2), Edge(2,3,6)}),
            Node(3, {Edge(3,0,9), Edge(3,2,6), Edge(3,4,2)}),
            Node(4, {Edge(4,0,1), Edge(4,3,2)})});
    // Djikstra's Algorithm
    cout << "Shortest distance: " << to_string(djikstra(g,0,0).first)
       << ", Path: " << djikstra(g,0,0).second << endl; 
    cout << "Shortest distance: " << to_string(djikstra(g,0,1).first)
       << ", Path: " << djikstra(g,0,1).second << endl; 
    cout << "Shortest distance: " << to_string(djikstra(g,0,2).first)
       << ", Path: " << djikstra(g,0,2).second << endl; 
    cout << "Shortest distance: " << to_string(djikstra(g,0,3).first)
       << ", Path: " << djikstra(g,0,3).second << endl; 
    cout << "Shortest distance: " << to_string(djikstra(g,0,4).first)
       << ", Path: " << djikstra(g,0,4).second << endl; 
    return 0;
}

