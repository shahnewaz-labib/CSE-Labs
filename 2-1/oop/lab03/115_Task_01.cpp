#include <iostream>
using namespace std;

class Counter {
private:
    int count, step;
public:
    Counter() {
        count = step = 0;
    }
    void setIncrementStep(int step_val) {
        step = step_val;
    }
    int getCount() {
        return count;
    }
    void increment() {
        count += step;
    }
    void resetCount() {
        count = 0;
    }
};




int main() {

}
