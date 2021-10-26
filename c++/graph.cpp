#include <iostream>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

int main() {
    vector<pair<int,int> > edges;
    edges.push_back(make_pair(1,2));
    edges.push_back(make_pair(2,5));
    for (auto e : edges) {
        cout << e.first << ", " << e.second << endl;
    }

    vector<tuple<int,int,int> > weighted_edges;
    weighted_edges.push_back(make_tuple(1,2,3));
    weighted_edges.push_back(make_tuple(2,3,7));
    for (auto e : weighted_edges) {
        cout << get<0>(e) << ", " << get<1>(e) << ", " << get<2>(e) << endl;
    }
    return 0;
}
