#include <iostream>
#include <fstream>
#define MAX 100
using namespace std;
int X[MAX]; // phương án tối ưu của bài toán
int n; //số lượng đồ vật
float b, weight=0; //trọng lượng túi
float cost=0; // giá trị sử dụng phương án hiện tại
int XOPT[MAX]; //phương án tối ưu của bài toán
float FOPT=0; //giá trị tối ưu của bài toán
float A[MAX], C[MAX];//vector trọng lượng và giá trị sử dụng
void Init (void) { //đọc dữ liệu
	ifstream fp("caitui.in"); fp>>n;fp>>b;
	for(int i=1; i<=n; i++){
		fp>>A[i]>>C[i];
	}
	fp.close();
}
void Result(void) {//đưa ra giá trị và phương án tối ưu
	cout<<"Giá trị tối ưu:"<<FOPT<<endl;
	cout<<"Phương án tối ưu:";
	for(int i=1; i<=n; i++)
	cout<<XOPT[i]<<" ";
}
void Update(void) { //cập nhật phương án tối ưu
	if (cost> FOPT){
		FOPT =cost;
		for (int i=1; i<=n; i++)
			XOPT[i]=X[i];
	}
}
void Back_Track(int i){
	int j, t = (int)((b-weight)/A[i]); //giá trị khởi đầu
	for(int j= t; j>=0; j--){
		X[i] = j;
		weight = weight+A[i]*X[i]; //trọng lượng phương án bộ phận
		cost = cost + C[i]*X[i]; //giá trị phương án bộ phận
		if (i==n) Update(); //ghi nhận kỷ lục
		else if ( cost + ( C[i+1]*((b- weight)/A[i+1]))>FOPT) //kiểm tra cận
		Back_Track(i+1);
		weight = weight-A[i]*X[i];
		cost = cost - C[i]*X[i];
	}
}
int main (void ){ //chương trình chính
	Init(); Back_Track(1);Result();
}