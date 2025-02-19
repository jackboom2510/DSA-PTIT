#include <bits/stdc++.h>

using namespace std;

int main() {
	long long S = 0;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		S += pow(-1, i+1)*i;
	}
	cout << S << endl;
	return 0;
}