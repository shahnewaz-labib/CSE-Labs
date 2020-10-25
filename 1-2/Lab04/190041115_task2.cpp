/*
          __      __    _ __  
         / /___ _/ /_  (_) /_ 
        / / __ `/ __ \/ / __ \
       / / /_/ / /_/ / / /_/ /
 _____/_/\__,_/_.___/_/_.___/ 
/_____/                       

*/

#include "bits/stdc++.h"
#define fastio              ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
#define read                freopen("input.txt", "r", stdin);
#define write               freopen("output.txt", "w", stdout);
#define TC                  int t,tc;cin>>t;for(tc=1;tc<=t;tc++)
#define                     all(v) (v).begin(),(v).end()
#define                     rall(v) (v).rbegin(),(v).rend()
#define mem(v,n)            memset(v,n,sizeof v)
#define nl                  '\n'
#define pii                 pair<int,int>
#define vi                  vector<int>
#define vll                 vector<ll>
#define ll                  long long
#define ff                  first
#define ss                  second
#define eb                  emplace_back
#define MAX(a,b)            (a)>(b)?(a):(b)
#define MIN(a,b)            (a)<(b)?(a):(b)
#define sq(x)               (x)*(x)

#define debug(x)            cerr<<#x<<" = "<<x<<nl

using namespace std;

string cat(string s, int k) {
    if(k == 0) return "";
    return s + cat(s, k-1);
}

int SUM(string n) {
   if(n.empty()) return 0;
    int a = n.back()-'0';
    n.pop_back();
    return a+SUM(n);
}

int SUM_NUM(int n) {
    if(n == 0) return 0;
    return n%10+SUM_NUM(n/10);
}

int solve(int sum) {
    if(sum < 10) return sum;
    // solve(SUM(to_string(sum)));
    solve(SUM_NUM(sum));
}

int digital_root(int n) {
    return 1+(n-1)%9;
}

int main() {
    string n; int k; cin >> n >> k;
    // n = cat(n, k);
    // oneliner solution :
    // cout << digital_root(sum) << '\n';
    int sum = k*SUM(n);
    if(sum < 10) {cout << sum << endl; return 0;}
    cout << solve(sum) << endl;

    return 0;
}
