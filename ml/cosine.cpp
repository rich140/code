#include <vector>
#include <stdexcept>
#include <math.h>

// Returns the cosine similarity between two n-dimensional vectors
// cos(0) = x*y/|xy| where * is the dot product
// and 0 is the angle between x and y
double cosine_sim(std::vector<int> x, std::vector<int> y) {
    if (x.size() != y.size()) {
        throw std::invalid_argument("Size mismatch");
    } 
    int n = x.size();
    double dot = 0; // dot product
    double dist_x, dist_y = 0; // distances
    for (int i = 0; i < n; i++) {
        dot += x[i]*y[i];
        dist_x += x[i]*x[i];
        dist_y += y[i]*y[i];
    }
    dist_x = sqrt(dist_x);
    dist_y = sqrt(dist_y);
    return dot/(dist_x*dist_y); 
}
