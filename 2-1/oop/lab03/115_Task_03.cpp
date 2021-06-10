#include <iostream>
#include <cstring>
using namespace std;

class Product {
private:
    char name[100];
    double discountPercent, unitPrice;
public:
    Product() {
        unitPrice = 10;
        discountPercent = 0.5;
    }
    void assignName(const char *Name) {         
        strcpy(name, Name);
    }
    void setPrice(double price) {
        if(price >= 0) {
            unitPrice = price;
        } else cout << "Invalid price\n";
    }
    void setDiscPercent(double percent) {
        if(percent >= 0 and percent <= 10) {
            discountPercent = percent;
        } else cout << "Invalid discount\n";
    }

    double getSellingPrice(int nos) {
        return nos * (unitPrice - (unitPrice * discountPercent / 100));
    }

    void display() {
        cout << name << " has a unit price BDT " << unitPrice << ". Current discount " << discountPercent << "%.\n";
    }

};

int main() {

}
