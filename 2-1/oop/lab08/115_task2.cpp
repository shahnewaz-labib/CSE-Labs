#include <iostream>
#include <vector>
using namespace std;


class Lab {
    string labName;
    int capacity;

public: 
    // Constructor
    Lab(string N = "", int c = 0) {
        labName = N;
        capacity = c;
    }
    
    // getters

    string getLabName() { 
        return labName;
    }
    int getCapacity() { 
        return capacity; 
    }

    // Setters

    void setLabName(string s) { 
        labName = s; 
    }
    void setCapacity(int c) { 
        capacity = c;
    } 

    // To show info

    void show() {
        cout << labName << " " << capacity << " capacity\n";
    }
};


class LecturerRoom {
    string roomName;
    int roomNo, capacity;

public: 
    // Constructor
    LecturerRoom(string name = "", int no = 0, int c = 0) {
        roomName = name;
        roomNo = no;
        capacity = c;
    }

    // Getters

    string getRoomName() { 
        return roomName; 
    }
    int getRoomNo() { 
        return roomNo; 
    }
    int getCapacity() { 
        return capacity; 
    }

    // Setters

    void setRoomName(string s) { 
        roomName = s; 
    }
    void setRoomNo(int n) { 
        roomNo = n; 
    }
    void setCapacity(int c) { 
        capacity = c; 
    } 

    // To show info

    void show() {
        cout << roomName << " " << roomNo << " " << capacity << " capacity\n";
    }
};

class N28Building {
    vector<Lab> labList;
    vector<LecturerRoom> lecturerRoomList;

public:

    // Adding lab and lecturer room to the building

    void addLab(Lab a) { 
        labList.push_back(a); 
    }
    void addLecturerRoom(LecturerRoom a) {
        lecturerRoomList.push_back(a);
    }

    // Showing info

    void showAllLabs() {
        cout << "Showing all Labs:\n";
        for (Lab i : labList) i.show();
    }

    void showAllLecturerRooms() {
        cout << "Showing all Lecturer Rooms: \n";
        for (LecturerRoom i : lecturerRoomList) i.show();
    }
};

int main() {

    // Dummy values

    Lab lab1("X", 30);
    Lab lab2("Y", 40);
    Lab lab3("Z", 50);
    Lab lab4("F", 60);

    LecturerRoom lecturerRoom1("A", 101, 3);
    LecturerRoom lecturerRoom2("B", 102, 3);
    LecturerRoom lecturerRoom3("C", 103, 3);
    LecturerRoom lecturerRoom4("E", 104, 3);

    N28Building Building;

    // Inserting dummy values

    Building.addLab(lab1);
    Building.addLab(lab2);
    Building.addLab(lab3);
    Building.addLab(lab4);

    Building.addLecturerRoom(lecturerRoom1);
    Building.addLecturerRoom(lecturerRoom2);
    Building.addLecturerRoom(lecturerRoom3);
    Building.addLecturerRoom(lecturerRoom4);

    // Showing dummy values

    Building.showAllLabs();
    Building.showAllLecturerRooms();
}
