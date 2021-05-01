#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mxn = 1e6+10;
int ar[mxn], total;

int Iterative_binary_search(int x, int *arr) {
	int i=0, j=total-1;
	while(i<=j){
		int m=i+(j-i)/2;
		if(arr[m]==x) return m;
		else if(arr[m]>x)j=m-1;
		else i=m+1;
	}
	return -1;
}

int Recursive_binary_search(int x, int *arr, int l, int r) {
	int m=l+(r-l)/2;
	if(l>=r) return -1;
	if(arr[m]==x) return m;
	else if(arr[m]>x) return Recursive_binary_search(x, ar, l, m-1);
	else return Recursive_binary_search(x, ar, m+1, r);
	
	return 6969; // to check if this line is ever reached
				 // not really sure
}

int main() {
    int x,i;
    for(i=0; ;i++){
        cin>>x;
        if(x<0)break;
        ar[i]=x;
    }
    cin>>x;
    total=i;
    cout << Iterative_binary_search(x, ar) << " (using iteration)\n";
    cout << Recursive_binary_search(x, ar, 0, total-1) << " (using recursion)\n";

    
    
}