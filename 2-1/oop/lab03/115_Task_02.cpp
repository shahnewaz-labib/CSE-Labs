#include <iostream>
using namespace std;

class RationalNumber {
private:
    int numerator, denominator;
public:
    void assign(int Numerator, int Denominator) {
        if (denominator == 0) {
            cout << "Invalid Denominator\n";
            return;
        }
        numerator = Numerator;
        denominator = Denominator;
    }
    double convert() {
        return numerator / (double) denominator;
    }
    void invert() {
        swap(numerator, denominator);
    }
    void print() {
        cout << numerator << "/" << denominator << "\n";
    }
};

int main() {

}
