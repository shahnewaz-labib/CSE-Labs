#include <bits/stdc++.h>
using namespace std;
class FLOAT {

private:
    float data;
public:
    FLOAT() : data(0) {

    }

    FLOAT(float x) : data(x) {

    }

    void setValue(float x) {
        data = x;
    }
    void Display() {
        cout << "Data: " << data << "\n";
    }

    FLOAT operator+(FLOAT f) {
        return FLOAT(data + f.data);
    }

    FLOAT operator-(FLOAT f) {
        return FLOAT(data - f.data);
    }

    FLOAT operator*(FLOAT f) {
        return FLOAT(data * f.data);
    }
    FLOAT operator/(FLOAT f) {
        if (f.data != 0)
            return FLOAT((data*1.0) / f.data);

        cout << "can't divide by zero" << "\n";
        return FLOAT(0);
    }

    operator int() const {
        return int(data);
    }

};

int main() {
    FLOAT f1(5.7), f2(9.8), f3, f4;
    f4 = f2 / f1;
    int i = f1;
    cout << "Int: " << i << endl;

}
