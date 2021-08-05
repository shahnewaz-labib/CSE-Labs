#include <bits/stdc++.h>

using namespace std;
class ZooAnimal
{
private:
    string nameOfAnimal;
    int birthyear;
    int cageNumber;
    double weightData;
    int height;

public:
    ZooAnimal() : birthyear(2021), cageNumber(0), weightData(0.0), height(0), nameOfAnimal("blank") {

    }
    void set_name(string name) {
        nameOfAnimal = name;
    }
    void set_birthyear(int birth) {
        birthyear = birth;
    }
    void set_cageNo(int cage) {
        cageNumber = cage;
    }
    void set_weight(double w) {
        weightData = w;
    }
    void set_height(int h) {
        height = h;
    }
    string get_name() const {
        return nameOfAnimal;
    }
    int get_birthyear() const {
        return birthyear;
    }
    int get_cagenumber() const {
        return cageNumber;
    }
    double get_weight() const {
        return weightData;
    }
    int get_height() const {
        return height;
    }
    int get_age() const {
        return 2021 - birthyear;
    }
    void getInformation() {
        cout << "Name of Animal: " << nameOfAnimal << "\n";
        cout << "Birthyear     : " << birthyear << "\n";
        cout << "Cage Number   : " << cageNumber << "\n";
        cout << "Weight        : " << weightData << "\n";
        cout << "Height        : " << height << "\n";
    }
    int operator==(int data) {
        return weightData == data;
    }
    void operator--(int n) {
        height -= n;
    }
};
int main() {

}
