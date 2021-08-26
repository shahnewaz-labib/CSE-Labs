#include <bits/stdc++.h>

using namespace std;
class User
{
    string username;
    string password;
    virtual void showmenu() = 0;
};
class Teacher : public User
{
public:
    void showmenu()
    {
        cout << "1.View students" << endl;
        cout << "2.Mark student" << endl;
        cout << "3.Show copies" << endl;
    }
};
class Student : public User
{
public:
    void showmenu()
    {
        cout << "1.View task" << endl;
        cout << "2.Submit task" << endl;
    }
};
int main()
{
    //User u1; //error
    Teacher t1;
    t1.showmenu();
    Student s1;
    s1.showmenu();
}
