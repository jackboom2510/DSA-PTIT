#include <iostream>
#include <iomanip>
#define MAX 100
using namespace std;
int X[MAX], n, dem = 0; // sử dụng các biến toàn cục X[], n, OK, dem
bool OK = true;
void Init() { // khởi tạo xâu nhị phân đầu tiên
	cout << "Nhập n=";
	cin >> n;
	for (int i = 1; i <= n; i++) // thiết lập xâu với n số 0
		X[i] = 0;
}
void Result() { // đưa ra xâu nhị phân hiện tại
	cout << "\n Xâu thứ " << ++dem << ":";
	for (int i = 1; i <= n; i++)
		cout << X[i] << setw(3);
}
void Next_Bits_String() { // thuật toán sinh xâu nhị phân kế tiếp
	int i = n;
	while (i > 0 && X[i]) {			  // duyệt từ vị trí bên phải nhất
		X[i] = 0; // nếu gặp X[i] = 1 ta chuyển thành 0
		i--;	  // lùi lại vị trí sau
	}
	if (i > 0) X[i] = 1; // gặp X[i] =0 đầu tiên ta chuyển thành 1
	else OK = false; // kết thúc khi gặp xâu có n số 1
}
int main(){			// đây là thuật toán sinh
	Init(); // thiết lập cấu hình đầu tiên
	while (OK){						// lặp khi chưa phải cấu hình cuối cùng
		Result();			// đưa ra cấu hình hiện tại
		Next_Bits_String(); // sinh ra cấu hình kế tiếp
	}
}