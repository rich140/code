#include <initializer_list>

using namespace std;

class Vector {
    private:
        double* elem;
        int sz;
    public:
        Vector(int s) : elem(new double[s]), sz(s) {
            for (int i = 0; i < s; i++) {
                elem[i] = 0;
            } 
        }
        Vector(std::initializer_list<double> lst)
            : elem(new double[lst.size()]), sz(static_cast<int>(lst.size())) {
                copy(lst.begin(), lst.end(), elem);
            }
        ~Vector() { delete[] elem; } // destructor
        double& operator[](int i);
        int size() const;
        void push_back(double);
};

int main() {
    return 0;
}
