#include <bits/stdc++.h>

using namespace std;

int main() {
	float S = 0;
	int n;
	cin >> n;
	for(int i = 0; i <= n; i++) {
		S += (float)(2*i+1)/(2*i+2);
	}
	cout << S << endl;
	return 0;
}