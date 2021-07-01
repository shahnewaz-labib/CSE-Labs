#include <iostream>
using namespace std;

class Calculator {
    int value;
public:
    Calculator(int val = 0) : value(val) {}
    ~Calculator() {
        cout << "Calculator object is destroyed.\n";
    }
    int getValue() {
        return value;
    }
    void setValue(int val) {
        value = val;
    }
    void add(int Value) {
        cout << "add " << Value << "\n";
        value += Value;
    }
    void subtract(int Value) {
        cout << "subtract " << Value << "\n";
        value -= Value;
    }
    void multiply(int Value) {
        cout << "multiply " << Value << "\n";
        value *= Value;
    }
    void divideBy(int Value) {
        cout << "divide by " << Value << "\n";
        if(value == 0) {
            value /= Value;
            return;
        }
        cout << "Error : divide by 0 is undefined.\n";

    }
    void clear() {
        value = 0;
    }
    void display() {
        cout << "Calculator display: " << value << "\n";
    }


};



int main() {
    Calculator c;
    c.add(10);
    c.display();

    c.add(7);
    c.display();

    c.multiply(31);
    c.display();

    c.subtract(42);
    c.display();

    c.divideBy(7);
    c.display();

    c.divideBy(0);
    c.display();

    c.add(3);
    c.display();

    c.subtract(1);
    c.display();

    c.clear();
}
