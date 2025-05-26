#include <bits/stdc++.h>>
using namespace std;

int ID = 0;
enum Faction {
	Player,
	Enemy,
	Neutral
};

enum Army {
	Sword = 1,
	Bow = 2,
	Axe = 3
};

class Troop {
public:
	int id, type;
	double quantity;
	Troop* next;
	bool isAlive;
	Faction faction;
public:
	Troop() : quantity(0), type(0), next(nullptr), isAlive(true), faction(Neutral)  {}
	Troop(double quantity_, int type_, Faction fac_) : quantity(quantity_), type(type_), next(nullptr), isAlive(true), faction(fac_) {}
	friend istream& operator>>(istream& is, Troop& t) {
		is >> t.quantity >> t.type;
		return is;
	}
};

int advantage(Troop A, Troop B) {
	if(A.type == B.type) return 0;
	else if((A.type == Sword && B.type == Bow) || (A.type == Bow && B.type == Axe) || (A.type = Axe && B.type == Bow)) return 1;
	return -1;
}

void connectTroop(Troop& A, Troop& B) {
	int adv = advantage(A, B);
	double a = A.quantity, b = B.quantity;
	if(A.faction == B.faction) {
		B.quantity += a;
		A.quantity = 0;
		if(a > b)
			B.type = A.type;
		else
			A.type = B.type;
	}
	else {
		if(A.quantity >= B.quantity) {
			if(!adv) A.quantity -= B.quantity;
			else if(adv == 1) A.quantity = A.quantity*1.5-B.quantity
			if(B.quantity*1.5 > A.quantity) {
				B.quanity = B.quanity*1.5
			}
			B.quantity = 0;
		}
	}
}


int main() {
	int N, M;
	cin >> N >> M;
	Troop A[N], B[M];
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		A[i].faction = Player;
		A[i].id = ID++;
	}
	for(int i = 0; i < M; i++) {
		cin >> B[i];
		B[i].faction = Enemy;
		B[i].id = ID++;
	}
	return 0;
}