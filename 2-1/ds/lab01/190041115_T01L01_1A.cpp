#include <bits/stdc++.h>
using namespace std;
const int mxn = 3e6+10;
int f[mxn];

struct pp{
    int konta, koybar;
    bool operator<(const pp &p){
        return p.koybar < koybar;
    }
};

vector<pp> v;

int main() {
    int x=1,mx=-1;
    while(x>0) {
        cin>>x;
        f[x]++;
        mx=max(mx,x);
    }
    assert(mx!=-1);
    for(int i=1;i<=mx;i++){
        if(f[i]){
            v.push_back({i,f[i]});
        }
    }
    sort(v.begin(),v.end());
    for(auto x:v){
        cout<<x.konta<<" occurs "<<x.koybar<<" times\n";
    }
    
    
}