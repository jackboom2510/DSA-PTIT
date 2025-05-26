#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Cấu trúc
enum Faction { PLAYER, ENEMY };
enum UnitClass { SWORD = 1, BOW = 2, AXE = 3 };

struct ArmyNode {
    int id;
    int quantity;
    UnitClass unitClass;
    Faction faction;
    ArmyNode* next;
    bool alive;

    ArmyNode(int _id, int _quantity, UnitClass _unitClass, Faction _faction)
        : id(_id), quantity(_quantity), unitClass(_unitClass), faction(_faction), next(nullptr), alive(true) {}
};

// Hàm chiến đấu
bool hasAdvantage(UnitClass a, UnitClass b) {
    return (a == SWORD && b == BOW) ||
           (a == BOW && b == AXE) ||
           (a == AXE && b == SWORD);
}

ArmyNode* merge(ArmyNode* a, ArmyNode* b, int& nextID) {
    int totalQuantity = a->quantity + b->quantity;
    UnitClass dominantClass = (a->quantity >= b->quantity) ? a->unitClass : b->unitClass;
    ArmyNode* merged = new ArmyNode(nextID++, totalQuantity, dominantClass, a->faction);
    a->alive = false;
    b->alive = false;
    a->next = b; // Liên kết a -> b
    return merged;
}

ArmyNode* combat(ArmyNode* a, ArmyNode* b, int& nextID) {
    int qa = a->quantity;
    int qb = b->quantity;

    if (hasAdvantage(a->unitClass, b->unitClass)) {
        qa += qa / 2;
    } else if (hasAdvantage(b->unitClass, a->unitClass)) {
        qb += qb / 2;
    }

    if (qa > qb) {
        a->quantity = qa - qb;
        b->alive = false;
    } else if (qb > qa) {
        b->quantity = qb - qa;
        a->alive = false;
    } else {
        a->alive = false;
        b->alive = false;
    }

    a->next = b; // Liên kết a -> b
    return a->alive ? a : (b->alive ? b : nullptr);
}


// Thuật toán chính:
void processArmies(std::vector<ArmyNode*>& players, std::vector<ArmyNode*>& enemies) {
    int nextID = players.size() + enemies.size();

    // Bước 1: Đối đầu các cặp có lợi
    for (auto& p : players) {
        if (!p->alive) continue;
        for (auto& e : enemies) {
            if (!e->alive) continue;
            if (hasAdvantage(p->unitClass, e->unitClass)) {
                combat(p, e, nextID);
                break;
            }
        }
    }

    // Bước 2: Merge các node còn lại cùng phe
    std::vector<ArmyNode*> newPlayers;
    for (size_t i = 0; i + 1 < players.size(); i += 2) {
        if (players[i]->alive && players[i + 1]->alive) {
            newPlayers.push_back(merge(players[i], players[i + 1], nextID));
        } else {
            if (players[i]->alive) newPlayers.push_back(players[i]);
            if (players[i + 1]->alive) newPlayers.push_back(players[i + 1]);
        }
    }
    if (players.size() % 2 == 1 && players.back()->alive) {
        newPlayers.push_back(players.back());
    }
    players = newPlayers;

    std::vector<ArmyNode*> newEnemies;
    for (size_t i = 0; i + 1 < enemies.size(); i += 2) {
        if (enemies[i]->alive && enemies[i + 1]->alive) {
            newEnemies.push_back(merge(enemies[i], enemies[i + 1], nextID));
        } else {
            if (enemies[i]->alive) newEnemies.push_back(enemies[i]);
            if (enemies[i + 1]->alive) newEnemies.push_back(enemies[i + 1]);
        }
    }
    if (enemies.size() % 2 == 1 && enemies.back()->alive) {
        newEnemies.push_back(enemies.back());
    }
    enemies = newEnemies;
}

// Hàm hiển thị danh sách liên kết
void printCombinedLinkedList(const std::vector<ArmyNode*>& allNodes) {
    for (const auto& node : allNodes) {
        if (node->alive) {
            ArmyNode* current = node;
            while (current) {
                std::string factionStr = (current->faction == PLAYER) ? "Player" : "Enemy";
                std::string classStr;
                switch (current->unitClass) {
                    case SWORD: classStr = "Sword"; break;
                    case BOW: classStr = "Bow"; break;
                    case AXE: classStr = "Axe"; break;
                }
                std::cout << "[" << factionStr << " ID: " << current->id
                          << ", Qty: " << current->quantity
                          << ", Class: " << classStr << "] -> ";
                current = current->next;
            }
            std::cout << "NULL\n";
        }
    }
}


// Hàm main
int main() {
    std::vector<ArmyNode*> players;
    std::vector<ArmyNode*> enemies;
    std::vector<ArmyNode*> allNodes;
    int N, M;
    int idCounter = 0;

    std::cout << "Nhap so luong node ben Player (N) va Enemy (M): ";
    std::cin >> N >> M;

    std::cout << "Nhap thong tin cho " << N << " node cua Player (quantity unitClass):\n";
    for (int i = 0; i < N; ++i) {
        int qty, cls;
        std::cin >> qty >> cls;
        ArmyNode* node = new ArmyNode(idCounter++, qty, static_cast<UnitClass>(cls), PLAYER);
        players.push_back(node);
        allNodes.push_back(node);
    }

    std::cout << "Nhap thong tin cho " << M << " node cua Enemy (quantity unitClass):\n";
    for (int i = 0; i < M; ++i) {
        int qty, cls;
        std::cin >> qty >> cls;
        ArmyNode* node = new ArmyNode(idCounter++, qty, static_cast<UnitClass>(cls), ENEMY);
        enemies.push_back(node);
        allNodes.push_back(node);
    }

    processArmies(players, enemies);

    std::cout << "\nDanh sach lien ket tong hop:\n";
    printCombinedLinkedList(allNodes);

    // Giai phong bo nho
    for (auto& node : allNodes) delete node;

    return 0;
}
