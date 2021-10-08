#include <iostream>
#include <string>
#include <typeinfo>
#include <fstream>
using namespace std;

enum class Furniture_type
{
    tBed,
    tSofa
};

class Furniture
{
protected:
    string name;
    double price;
    double discount;
    static int n;
    static Furniture *arrap[];

public:
    virtual void getData()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter price: ";
        cin >> price;
        cout << "Enter discount: ";
        cin >> discount;
    }
    virtual void setData()
    {
        cout << "\n Name: " << name;
        cout << "\n price: " << price;
        cout << "\n discount: " << discount;
    }
    virtual Furniture_type getType();
    static void add();
    static void display();
    static void read();
    static void write();
};
int Furniture::n;
Furniture *Furniture::arrap[100];

class Bed : public Furniture
{
private:
    string sz;

public:
    void getData()
    {
        Furniture::getData();
        cout << "Enter size: ";
        cin >> sz;
    }
    void setData()
    {
        Furniture::setData();
        cout << "\n Size: " << sz;
    }
};

class Sofa : public Furniture
{
private:
    int cnt;

public:
    void getData()
    {
        Furniture::getData();
        cout << "Enter seat number: ";
        cin >> cnt;
    }
    void setData()
    {
        Furniture::setData();
        cout << "\n Seat number: " << cnt;
    }
};

void Furniture::add()
{
    char ch;
    cout << " 'b' to add a bed"
            "\n 's' to add a sofa"
            "\nEnter selection: ";
    cin >> ch;
    switch (ch)
    {
    case 'b':
        arrap[n] = new Bed;
        break;
    case 's':
        arrap[n] = new Sofa;
        break;
    default:
        cout << "Unknown furniture type\n";
        return;
    }
    arrap[n++]->getData();
}

void Furniture::display()
{
    for (int j = 0; j < n; j++)
    {
        cout << (j + 1);
        switch (arrap[j]->getType())
        {
        case Furniture_type::tBed:
            cout << ". Type: Bed";
            break;
        case Furniture_type::tSofa:
            cout << ". Type:Sofa";
            break;
        default:
            cout << ". Unknown type";
        }
        arrap[j]->setData();
        cout << endl;
    }
}

Furniture_type Furniture::getType()
{
    if (typeid(*this) == typeid(Bed))
        return Furniture_type::tBed;
    else if (typeid(*this) == typeid(Sofa))
        return Furniture_type::tSofa;
    else
    {
        cerr << "\nInvalid type";
        exit(0);
    }
    return Furniture_type::tBed;
}
void Furniture::write()
{
    int size;
    cout << "Writing " << n << " furnitures.\n";
    Furniture_type ftype;
    ofstream of;
    of.open("FURNITURES.DAT", ios::trunc | ios::binary);
    if (!of)
    {
        cout << "\nCan't open file\n";
        return;
    }
    for (int j = 0; j < n; j++)
    {
        ftype = arrap[j]->getType();
        of.write((char *)&ftype, sizeof(ftype));
        switch (ftype) //find its size
        {
        case Furniture_type::tBed:
            size = sizeof(Bed);
            break;
        case Furniture_type::tSofa:
            size = sizeof(Sofa);
            break;
        }
        of.write((char *)(arrap[j]), size);
        if (!of)
        {
            cout << "\nCanï¿½t write to file\n";
            return;
        }
    }
}

void Furniture::read()
{
    int size;
    Furniture_type ftype;
    ifstream inf; //open ifstream in binary
    inf.open("FURNITURES.DAT", ios::binary);
    if (!inf)
    {
        cout << "\nCan't open file\n";
        return;
    }
    n = 0;
    while (true)
    {
        inf.read((char *)&ftype, sizeof(ftype));
        if (inf.eof())
            break;
        if (!inf) //error reading type
        {
            cout << "\nCan't read type from file\n";
            return;
        }
        switch (ftype)
        {
        //make new employee
        case Furniture_type::tBed: //of correct type
            arrap[n] = new Bed;
            size = sizeof(Bed);
            break;
        case Furniture_type::tSofa:
            arrap[n] = new Sofa;
            size = sizeof(Sofa);
            break;
        default:
            cout << "\nUnknown type in file\n";
            return;
        }

        inf.read((char *)arrap[n], size);
        if (!inf) //error but not eof
        {
            cout << "\nCan't read data from file\n";
            return;
        }
        n++;
    }
    cout << "Reading " << n << " Furnitures\n";
}
int main()
{
    char ch;
    while (true)
    {
        cout << "'a' -- add data for an Furniture"
                "\n'd' -- display data for all Furnitures"
                "\n'w' -- write all Furniture data to file"
                "\n'r' -- read all Furniture data from file"
                "\n'x' -- exit"
                "\nEnter selection: ";
        cin >> ch;
        switch (ch)
        {
        case 'a': 
            Furniture::add();
            break;
        case 'd': 
            Furniture::display();
            break;
        case 'w': 
            Furniture::write();
            break;
        case 'r': 
            Furniture::read();
            break;
        case 'x':
            exit(0); //exit program
        default:
            cout << "\nUnknown command" << endl;
        }
    }
    return 0;
}
