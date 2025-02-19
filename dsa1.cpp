#include <bits/stdc++.h>

using namespace std;

int main() {
	int S = 0, n;
	cin >> n;
	for(int i = 0; i <= n; i++) {
		S += (2*i+1)/(2*i+2);
	}
	cout << S << endl;
	return 0;
}