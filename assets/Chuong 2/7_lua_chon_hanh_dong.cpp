#include <iostream>
#include <fstream>
#include <iomanip>
#define MAX 1000
using namespace std;
int Start[MAX], Finish[MAX], n, XOPT[MAX], dem=0;
//đọc dữ liêu từ file data.in
void Read_Data(){
	ifstream fp("data.in"); fp>>n;
	for (int i=1; i<=n; i++){
		fp>>Start[i];
		fp>>Finish[i];
		XOPT[i]=false;
	}
	fp.close();
}
//Sắp xếp tăng dần theo thời gian kết thúc các hành động
void Sapxep(void) {
	for(int i=1; i<=n-1; i++){
		for(int j=i+1; j<=n; j++){
			if(Finish[i]> Finish[j]){
				int t = Finish[i]; Finish[i]=Finish[j];Finish[i]=t;
				t = Start[i];Start[i]=Start[j];Start[i]=t;
			}
		}
	}
}
//đưa ra kết quả tối ưu
void Result(void){
	ofstream fp("ketqua.out");
	fp<<dem<<endl;
	for(int i=1; i<=n; i++){
		if(XOPT[i])
		fp<<i<<setw(3);
	}
}
void Greedy_Solution(void){ //Thuật toán tham lam
	Read_Data();//đọc dữ liêu từ file data.in
	Sapxep();//Bước 1: Sắp xếp
	int i =1; XOPT[i]=true; dem=1; //Bước 2. Khởi tạo
	for(int j=2; j<=n; j++){//Bước 3: lặp
		if(Finish[i]<=Start[j]){
			dem++; i = j; XOPT[i]=true;
		}
	}
	Result();//Bước 4. Trả lại kết quả
}
int main(void){
	Greedy_Solution();
}