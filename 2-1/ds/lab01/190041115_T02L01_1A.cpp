#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mxn = 1e3;
ll dp[mxn][mxn];

ll fact(int n){
    if(n==0 or n==1) return 1;
    else return n*fact(n-1);
}

ll f(int n){
    int ans=1;
    for(int i=1;i<=n;i++){
        ans*=i;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    cout<<f(n)<<" (using iteration)\n";
    cout<<fact(n)<<" (using recurtion)\n";
    
    
}