#include <iostream>
#define MAX 100
using namespace std;
int X[MAX], n;
void Result() {
	for(int i = 1; i <= n; i++)
		cout << X[i];
	cout << endl;
}

void Try(int i) {
	for(int j = 0; j <= 1; j++) {
		X[i] = j;
		if(i == n) Result();
		else Try(i+1);
	}
}

int main() {
	cin >> n;
	Try(0);
}