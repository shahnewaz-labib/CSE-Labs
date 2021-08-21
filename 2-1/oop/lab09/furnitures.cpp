#include <iostream>
#include <string>
using namespace std;

enum  Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
public:

    Furniture(double p=0,double d=0,Material m=Material::Wood,string name="blank")
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
        setProductName(name);
    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    void setDiscountPercentage(double val){
        if(val>0)
            discount = val/100 * price;
    }
    void setMadeof(Material val)
    {
        madeof=val;
    }
    void setProductName(string name)
    {
        productName = name;
    }
    string getMadeof()
    {
        if(madeof==Material::Wood)
            return string("Wood");
        else if(madeof==Material::Board)
            return string("Board");
        else if(madeof==Material::Steel)
            return string("Steel");
        else
            return string("");
    }

    void setBasicDetails(double p,double d,Material m){
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }

    void showBasicDetails(){
        if(productName!="blank")
            cout<<"Product Name     : "<<productName<<"\n";
            cout<<"Regular Price    : "<<price<<"\n";
            cout<<"Discounted Price : "<<price-discount<<"\n";
            cout<<"Material         : "<<getMadeof()<<"\n";
    }

    double getDiscountedPrice(){
        return price-discount;
    }

    virtual void productDetails() = 0;

};


enum class BedSize {Single,SemiDouble,Double};
enum class SofaSize {One,Two,Three,Four,Five};
enum class AlmirahSize {Two,Three,Four};

class Bed : public Furniture
{
    BedSize bedsize;
public:
    Bed(double p=0,double d=0,Material m=Material::Wood,BedSize b=BedSize::Single){
        setBasicDetails(p,d,m);
        bedsize = b;
    }

    string getBedSize(){
        if(bedsize == BedSize::Single){
            return string("Single");
        } 
        else if(bedsize == BedSize::Double){
            return string("Double");
        } 

        else if(bedsize == BedSize::SemiDouble){
            return string("SemiDouble");
        } 

        else {
            return string("");
        }
    }

    void productDetails()
    {
        cout<<"--------------------"<<'\n';
        showBasicDetails();
        cout<<"Bed Size : "<<getBedSize()<<"\n";
        cout<<"####################"<<'\n';
    }
};

class Sofa : public Furniture
{
    SofaSize sofasize;
    public:
    Sofa(double p=0,double d=0,Material m=Material::Wood,SofaSize s=SofaSize::Three){
        setBasicDetails(p,d,m);
        sofasize = s;
    }

    string getSofaSize(){
        if(sofasize==SofaSize::One)
            return string("One");
        else if(sofasize==SofaSize::Two)
            return string("Two");
        else if(sofasize==SofaSize::Three)
            return string("Three");
        else if(sofasize==SofaSize::Four)
            return string("Four");
        else if(sofasize==SofaSize::Five)
            return string("Five");
        else 
            return string("");
    }


    void productDetails(){
        cout<<"--------------------"<<'\n';
        showBasicDetails();
        cout<<"Number of seats : "<<getSofaSize()<<"\n";
        cout<<"####################"<<'\n';

    }

};

class Almirah:public Furniture
{
    AlmirahSize almirahsize;
    public:
    Almirah(double p=0,double d=0,Material m=Material::Wood,AlmirahSize a=AlmirahSize::Two){
        setBasicDetails(p,d,m);
        almirahsize = a;
    }

    string getAlmirahSize(){
        if(almirahsize==AlmirahSize::Two)
            return string("Two");
        else if(almirahsize==AlmirahSize::Three)
            return string("Three");
        else if(almirahsize==AlmirahSize::Four)
            return string("Four");
        else
            return string("");
    }

    void productDetails(){
        cout<<"--------------------"<<'\n';
        showBasicDetails();
        cout<<"Number of doors : "<<getAlmirahSize()<<"\n";
        cout<<"####################"<<'\n';

    }
};

void sort_furniture_discount(Furniture** b, int n) {
    for (int i = 0; i < n ; ++i) {
        for (int j = i + 1; j < n; j++) {

            if(b[i]->getDiscountedPrice() < b[j]->getDiscountedPrice()){
                Furniture *tmp=b[i];
                b[i] = b[j];
                b[j] = tmp;
            }

        }
    }
}




int main()
{
    Furniture* f_list[100];

    /**
        task 1
        So that following lines can be executed without error
    */

    f_list[0] = new Bed(10000,123,Material::Wood,BedSize::Single);
    f_list[1] = new Sofa(11000,234,Material::Steel,SofaSize::Five);
    f_list[2] = new Almirah(13000,345,Material::Wood,AlmirahSize::Two);
    f_list[3] = new Bed(10090,123,Material::Wood,BedSize::Single);

    /**task 1 ends here*/

    /**
        task 2
        So that following lines can be executed without error

        task 3 (Modify productDetails)
    */

    f_list[2]->setDiscountPercentage(30);
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
    }

    /**task 2 ends here*/
    /**task 3 ends here*/


    cout << "\n\n";
    /**task 4
    So that following lines can be executed without error
    */
    sort_furniture_discount(f_list,4);
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
    }
    /**task 4 ends here*/

}
