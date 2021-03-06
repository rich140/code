#include <iostream>

using namespace std;

class complex {
    double re, im;
    public:
        complex(double r, double i) :re(r), im(i) {}
        complex(double r) :re(r), im(0) {}
        complex() :re(0), im(0) {}
        double real() const { return re; }
        void real(double d) { re=d; }
        double imag() const { return im; }
        void imag(double d) { im=d; }
        complex& operator+=(complex z) {
            re+=z.re, im+=z.im; return *this;
        }
        complex& operator-=(complex z) {
            re-=z.re, im-=z.im; return *this;
        }
        complex& operator*=(complex z); 
        complex& operator/=(complex z); 
};

complex operator+(complex a, complex b) { return a+=b; }
complex operator-(complex a, complex b) { return a-=b; }
complex operator-(complex a) { return (-a.real(), -a.imag()); }
bool operator==(complex a, complex b) {
    return a.real()==b.real() && a.imag()==b.imag();
}
bool operator!=(complex a, complex b) {
    return !(a==b);
}
complex sqrt(complex);

int main() {
    cout << "Complex Number Tests!" << endl;
    complex c(2, 3);
    cout << "Original: " << c.real() << "," << c.imag() << endl;
    complex c2(5, 6);
    complex c3 = c += c2;
    cout << "New" << c3.real() << "," << c3.imag() << endl;

    return 0;
}
