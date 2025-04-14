#include <iostream>
#include <vector>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:

    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}


    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }


    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }


    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0) out << " + " << c.imag << "i";
        else out << " - " << -c.imag << "i";
        return out;
    }


    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }
};
int main() {
    Complex c1, c2;


    cout << "Enter first complex number:" << endl;
    cin >> c1;
    cout << "Enter second complex number:" << endl;
    cin >> c2;


    cout << "\nFirst complex number: " << c1 << endl;
    cout << "Second complex number: " << c2 << endl;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    cout << "\nSum: " << sum << endl;
    cout << "Difference: " << diff << endl;


    vector<Complex> complexList = {c1, c2, sum, diff};
    Complex totalSum;
    for (const auto& c : complexList) {
        totalSum = totalSum + c;
    }

    cout << "\nSum of all complex numbers in the list: " << totalSum << endl;

    return 0;
}

