#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main() {
	int x=1;
	vector<int> v;
	vector<pii> ans;
	while(x){
		cin>>x;
		if(x) v.push_back(x);
	}
	cin>>x;
	int n=v.size();
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(v[i]+v[j] == x) ans.push_back({i+1, j+1});
		}
	}
	if(ans.empty()) {
		cout<<"No pair found!";
		return 0;
	}
	cout << ans.size() << " pairs:\n";
	for(pii x : ans) {
		printf("(worker-%d, worker-%d)\n", x.first, x.second);
	}
}
