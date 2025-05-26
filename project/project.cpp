#include <bits/stdc++.h>>
using namespace std;

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
	int quantity, type;
	Troop* next;
	bool isAlive;
	Faction faction;
public:
	Troop() : quantity(0), type(0), next(nullptr), isAlive(true), faction(Neutral)  {}
	Troop(int quantity_, int type_, Faction fac_) : quantity(quantity_), type(type_), next(nullptr), isAlive(true), faction(fac_) {}
	friend istream& operator>>(istream& is, Troop& t) {
		is >> t.quantity >> t.type;
		return is;
	}
};

void connectTroop(Troop& A, Troop& B) {
	if(A.faction == B.faction) {
		if(A.quantity > B.quantity) B.type = A.type;
		else A.type = B.type;
	}
	else {
		if(A.quantity >= B.quantity) {
			A.quantity -= B.quantity;
			B.quantity = 0;
		}
	}
	A->next = B;
}


int main() {
	return 0;
}