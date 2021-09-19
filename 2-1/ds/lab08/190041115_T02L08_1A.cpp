#include <bits/stdc++.h>
#define ll long long 
using namespace std;

class HashBase{
public:
    const int freeSlot = -1;
    ll *arr;
    int maxCollision,numOfkeys=0,tableSize;
    double LoadFactor=0;

    void init(int n,int mc){
        arr = new ll[n];
        tableSize = n;
        fill(arr,arr+n,freeSlot);
        maxCollision = mc;
    }

    virtual ll hash(ll key) { return key % tableSize; }
    virtual ll f(int i) { return i; };
    
    virtual ll getIndex(ll key,int i=0){
        return ( hash(key) + f(i)%tableSize ) % tableSize;
    }

    bool insert(ll key){
        ll ind;
        for(int i=0;i<maxCollision;i++){
            ind = getIndex(key,i);
            if(arr[ind] == freeSlot){
                numOfkeys++;
                arr[ind] = key;
                LoadFactor = numOfkeys/(double)tableSize;
                cout<<"Inserted "<<key<<"\tat Index "<<ind<<"\tL.F="<<LoadFactor<<'\n';
                return 1;
            } else {
                cout<<"Collision at Index-"<<ind<<"\n";
            }
        }
        cout<<"Insertion of "<<key<<" Failed"<<"\n";
        return 0;
    }
};

class Hash_LinearProbing:public HashBase{
public:
    Hash_LinearProbing(int n,int mc=6){ init(n,mc); }
};

class Hash_QuadraticProbing:public HashBase{
public:
   ll f(int i){ return i*i; }
   Hash_QuadraticProbing(int n,int mc=6){ init(n,mc); }
};

class Hash_Double:public HashBase{
public:
    ll R;

    ll hash2(ll key){
        return R - key%R;
    }
    ll getIndex(ll key,int i=0){
        return ( hash(key) + (f(i)*hash2(key))%tableSize ) % tableSize;
    }

    Hash_Double(int n,int mc=6,ll _R=7){ init(n,mc);R=_R; }
};

int main(){
    const int mc=6;

    HashBase *H;
    int type,n,q;
    cin>>type>>n>>q;
    
    if(type==1) H=new Hash_LinearProbing(n,mc);
    else if(type==2) H=new Hash_QuadraticProbing(n,mc);
    else { H=new Hash_Double(n,mc); }

    for(int i=0;i<q;i++){
        cin>>n;
        H->insert(n);
    } 

    cout<<"\n";
    for(int i=0;i<H->tableSize;i++){
        cout<<"Index-"<<i<<" "<<H->arr[i]<<"\n";
    }
}

/*

1 10 7
35
45
73
36
5
24
13

*/
