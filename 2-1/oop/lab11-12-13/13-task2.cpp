#include <bits/stdc++.h>
using namespace std;
int x = 10;

namespace my_namespace {
	int x = 15;
}

int main() {
	cout << x << "\n" << my_namespace::x << "\n";
}
