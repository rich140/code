#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Graph Representation as Edge List (v1, v2, weight)
    vector< tuple<int,int,int> > edges;
    edges.push_back(tuple<int,int,int>(0,1,5));
    edges.push_back(tuple<int,int,int>(0,3,7));
    edges.push_back(tuple<int,int,int>(0,2,3));
    edges.push_back(tuple<int,int,int>(1,3,3));
    edges.push_back(tuple<int,int,int>(2,3,1));
    edges.push_back(tuple<int,int,int>(1,4,2));
    edges.push_back(tuple<int,int,int>(3,4,2));
    // Computes the shortest distance from vertex v
    // to all other vertices. Stores result in distance matrix
    int n = 5;
    vector<int> distance(n, 99999);
    distance[0] = 0;
    for (int i = 1; i <= n-1; i++) {
        for (auto e : edges) {
            int a, b, w;
            tie(a, b, w) = e;
            distance[b] = min(distance[b], distance[a]+w);
        }
    }
    for (auto d : distance) {
        cout << d << " ";
    }
    cout << endl;
    return 0;
}
