#include <bits/stdc++.h>
#define ll long long 
using namespace std;

class ZooAnimal {
    string nameOfAnimal;
    int birthYear, cageNo, height;
    double weight;
public:
    ZooAnimal(string name = "blank", int yob = 2021, int cage_no = -1, double w = -1, int h = -1) {
        nameOfAnimal = name;
        birthYear = yob;
        cageNo = cage_no;
        weight = w;
        height = h;
    }
    void setBirthYear(int year = 2021){
        if(year > 2021) {
            cout << "birthYear cant be more than 2021" << "\n";
            return;
        }
        birthYear = year;
    }
    void set_cageNo(int b) {
        birthYear = b;
    }
    void set_height(int h) {
        height = h;
    }
    void set_weight(double w) {
        weight = w;
    }
    
    int get_birthYear() {
        return birthYear;
    }
    int get_cageNo() { 
        return cageNo; 
    }
    int get_height() { 
        return height; 
    }
    double get_weight() { 
        return weight; 
    }
    int getAge(){ 
        return 2021 - birthYear; 
    }
    
    void showInfo() {
        cout << "Name of Animal : " << nameOfAnimal << "\n";
        cout << "Year of birth  : " << birthYear << "\n";
        cout << "Cage No        : " << cageNo << "\n";
        cout << "Weight         : " << weight << "\n";
        cout << "Height         : " << height << "\n";
    }
};

int main(){
    ZooAnimal z;
    z.showInfo();
}
