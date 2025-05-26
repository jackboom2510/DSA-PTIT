#include <iostream>
#include <iomanip>
#define MAX 100
using namespace std;
int X[MAX], n, dem = 0;
bool OK = true;
void Init() {
	cout << "\nNhap n:";
	cin >> n;
	for(int i = 1; i <= n; i++)
		X[i] = i;
}
void Result() {
	cout << "\nKet qua " << ++dem << ": ";
	for(int i = 1; i <= n; i++)
		cout << X[i] << setw(3);
}
void Next_Combination() {
	int j = n-1;
	while(j > 0 && X[j] > X[j+1]) j--;
	if(j > 0) {
		int k = n;
		while(X[j] > X[k]) k--;
		int t = X[j]; X[j] = X[k]; X[k] = t;
		int r = j+1, s = n;
		while(r <= s) {
			t = X[r]; X[r] = X[s]; X[s] = t;
			r++; s--;
		}
	}
	else OK = false;
}
int main() {
	Init();
	while(OK) {
		Result();
		Next_Combination();
	}
}