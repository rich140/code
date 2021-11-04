#include <vector>
#include <stdexcept>

// Returns the Jaccard similarity between two n-dimensional vectors
// Assume vectors have 0 for empty values
// J(A,B) = |A^B|/|AUB|
double jaccard_sim(std::vector<int> a, std::vector<int> b) {
    if (a.size() != b.size()) {
        throw std::invalid_argument("Size mismatch");
    }
    double in, u = 0; // number of elements in intersection (resp. union)
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] != 0 && b[i] != 0) {
            in++;
            u++;
        } else if (a[i] != 0 || b[i] != 0) {
            u++;
        } else {}
    }
    return in/u; 
}

