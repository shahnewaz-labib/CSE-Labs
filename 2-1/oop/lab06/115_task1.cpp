#include <bits/stdc++.h>
#define sq(x) x*x
using namespace std;

class Coordinate {
private:
    double abscissa, ordinate;
public:

    Coordinate(int x = 0, int y = 0) {
        abscissa = x, ordinate = y;
    }
    ~Coordinate() {

    }

    double getDistance(Coordinate c) {
        return sqrt(sq(abscissa - c.abscissa) + sq(ordinate - c.ordinate));
    }
    double getDistance() {
        return sqrt(sq(abscissa) + sq(ordinate));
    }
    void move_abscissa(double val) {
        abscissa += val;
    }
    void move_ordinate(double val) {
        ordinate += val;
    }
    void move(double val) {
        move_abscissa(val);
        move_ordinate(val);
    }

    int operator==(Coordinate &c) {
        return getDistance() == c.getDistance();
    }
    int operator!=(Coordinate &c) {
        return getDistance() != c.getDistance();
    }
    int operator>(Coordinate &c) {
        return getDistance() > c.getDistance();
    }
    int operator<(Coordinate &c) {
        return getDistance() < c.getDistance();
    }
    int operator>=(Coordinate &c) {
        return getDistance() >= c.getDistance();
    }
    int operator<=(Coordinate &c) {
        return getDistance() <= c.getDistance();
    }
    const Coordinate operator++(int) { // postfix
        return Coordinate(abscissa++, ordinate++);
    }
    const Coordinate operator++() { // prefix
        return Coordinate(++abscissa, ++ordinate);
    }
    const Coordinate operator--(int) { // postfix
        return Coordinate(abscissa--, ordinate--);
    }
    const Coordinate operator--() { // prefix
        return Coordinate(--abscissa, --ordinate);
    }
    void display() const {
        cout << "Abscissa: " << abscissa << "\n";
        cout << "Ordinate: " << ordinate << "\n";
    }


};

int main() {
    Coordinate c, a;
    a = c++;
    cout << (a == c) << "\n";
}
