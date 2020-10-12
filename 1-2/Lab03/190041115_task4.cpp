#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ans[100000];
void preprocess() {
    ans[1] = 2;
    for(int i = 2; i < 100000; i++)
        ans[i] = i-1 + i*2 + ans[i-1];
    return;
}

int solve(int x) {
	int l = 0, r = 100000-1;
	while(l <= r) {
		int mid = l+(r-l)/2;
		if(ans[mid] > x) r = mid-1;
		else l = mid+1;
	}
	return r;
}

int main() {
    preprocess();
    int t; cin >> t;
    for(int i = 0; i <= 15; i++) cout << ans[i] << " "; cout << endl;
    while(t--) {
        int n;
        cin >> n;
        int count = 0;
        while(n >= 2) {
            n -= ans[solve(n)];
            count++;
        }
        cout << count << '\n';

    }
    return 0;
}
