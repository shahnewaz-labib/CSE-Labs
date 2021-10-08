#include <iostream>     
#include <algorithm>    
#include <vector>       
using namespace std;

int main () {
    int even[] = {2,4,6,8,10};
    int odd[] = {1,3,5,7,9};
    vector<int> v(10);

    merge(even,even+5,odd,odd+5,v.begin());

    for(int x : v) cout << x << " ";
    cout << "\n";
}
