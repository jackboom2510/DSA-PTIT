#include <iomanip>
#include <iostream>

using namespace std;
#define MAX 100
// Biểu diễn liên tục:
typedef struct {
    int inp;        // dùng để đưa phần tử vào hàng đợi
    int out;        // dùng để lấy phần tử ra khỏi hàng đợi
    int node[MAX];  // các node thông tin của hàng đợi
} queue;
// Biểu diễn rời rạc:
struct node {           // định nghĩa cấu trúc node
    int infor;          // thành phần dữ liệu
    struct node *next;  // thành phần liên kết
} *queue;

// Cài đặt hàng đợi tuyến tính dựa vào mảng :
class Queue {  // định nghĩa lớp queue
   public:
    int node[MAX];           // các node của queue
    int inp;                 // dùng để đưa phần tử vào hàng đợi
    int out;                 // dùng để lấy phần tử ra khỏi hàng đợi
    void Push() {            // đưa phần tử vào hàng đợi
        int value;           // giá trị node
        if (inp == MAX - 1)  // nếu hàng đợi tràn
            cout << "Tràn hàng đợi " << endl;
        else {              // nếu hàng đợi chưa đầy
            if (out == -1)  // trường hợp hàng đợi rỗng
                out = 0;    // lấy vị trí out = 0
            cout << "Giá trị node : ";
            cin >> value;
            inp = inp + 1;      // tăng con trỏ inp
            node[inp] = value;  // lưu trữ nội dung node
        }
    }
    void Pop() {                       // lấy phần tử ra khỏi hàng đợi
        if (out == -1 || out > inp) {  // trường hợp hàng đợi rỗng
            cout << "Queue rỗng" << endl;
            return;
        } else {  // trường hợp hàng đợi không rỗng
            cout << " Node được lấy ra : " << node[out] << endl;
            out = out + 1;
        }
    }
    void Display() {    // duyệt các node trong hàng đợi
        if (out == -1)  // trường hợp hàng đợi rỗng
            cout << "Queue is empty " << endl;
        else {
            cout << "Nội dung hàng đợi : ";
            for (int i = out; i <= inp; i++) cout << node[i] << setw(3);
            cout << endl;
        }
    }
    Queue(void) {  // constructor của lớp
        inp = -1;  // điểm vào thiết lập -1
        out = -1;  // điểm ra thiết lập -1
    }
};
// Cài đặt hàng đợi dựa vào danh sách liên kết
typedef struct node {  // định nghĩa một node
    int data;          // thành phần dữ liệu
    node *next;        // thành phần liên kết
};
class Queue {  // xây dựng lớp queue
   public:
    node *start;       // đây là con trỏ đến node đầu tiên
    node *end;         // /đây là con trỏ đến node cuối cùng
    node *np;          // /sử dụng một con trỏ trung gian
    void Push(void) {  // đưa phần tử vào hàng đợi
        int value;     // giá trị node cần thêm
        cout << "Giá trị node:";
        cin >> value;
        np = new node;         // cấp phát miền nhớ cho node
        np->data = value;      // thiết lập dữ liệu cho node
        np->next = NULL;       // thiết lập liên kết cho node
        if (start == NULL) {   // nếu danh sách rỗng
            start = end = np;  // node đầu và node cuối là một
            end->next = NULL;  // cuối cùng là NULL
        } else {               // trường hợp danh sách rỗng
            end->next = np;    // node cuối cùng là np
            end = np;          // đây là node cuối mới
            end->next = NULL;  // thiết lập liên kết cho end
        }
    }
    int Pop() {  // lấy phần tử ra khỏi hàng đợi
        int x;
        if (start == NULL) {  // nếu danh sách rỗng
            cout << "Hàng đợi rỗng" << endl;
        } else {                  // trường hợp hàng đợi không rỗng
            np = start;           // np trỏ đến node đầu danh sách
            x = np->data;         // đây là nội dung node loại bỏ
            start = start->next;  // dịch chuyển lên một node
            delete (np);          // giải phóng node đầu tiên
            return (x);
        }
    }
    void Display(void) {  // duyệt hàng đợi
        np = start;
        if (np == NULL)
            cout << "Hàng đợi rỗng" << endl;
        else {
            cout << "Nội dung hàng đợi:";
            while (np != NULL) {
                cout << np->data << setw(3);
                np = np->next;
            }
            cout << endl;
        }
    }
    Queue(void) {  // constructor của lớp
        start = NULL;
        end = NULL;
        np = NULL;
    }
};

struct node {           // biểu diễn node của hàng đợi ưu tiên
    int priority;       // mức độ ưu tiên của node
    int data;           // thành phần thông tin của node
    struct node *next;  // thành phần liên kết của node
};
class Priority_Queue {  // định nghĩa lớp Priority_Queue
   private:
    node *start;  // start là danh sách liên kết đơn
   public:
    Priority_Queue() {  // Constructor của lớp
        start = NULL;   // thiết lập lúc đầu là rỗng
    }
    void Push(int item, int priority);  // thêm node vào hàng đợi ưu tiên
    void Pop(void);                     // loại node khỏi hàng đợi ưu tiên
    void Display();                     // duyệt các node
};
void Priority_Queue::Push(int item, int priority) {  // thêm node với độ ưu tiên
    node *tmp, *q;
    tmp = new node;            // cấp phát miền nhớ cho node
    tmp->data = item;          // thiết lập thông tin của node
    tmp->priority = priority;  // thiết lập chế độ ưu tiên của node
    if (start == NULL || priority < start->priority) {  // trường hợp danh sách rỗng
        tmp->next = start;                              // tmp chỉ việc đặt ở đầu
        start = tmp;                                    // start bắt đầu từ đây
    } else {                                            // nếu start không rỗng
        q = start;                                      // q trỏ đến node đầu tiên
        // tìm vị trí phù hợp với độ ưu tiên của tmp
        while (q->next != NULL && q->next->priority <= priority) q = q->next;
        tmp->next = q->next;  // thiết lập liên kết cho tmp
        q->next = tmp;        // thiết lập liên kết cho q
    }
}
void Priority_Queue::Pop() {
    node *tmp;
    if (start == NULL)  // nếu hàng đợi rỗng
        cout << "Hàng đợi rỗng" << endl;
    else {
        tmp = start;  // tmp trỏ đến starrt
        cout << "Node bị loại: " << tmp->data << endl;
        start = start->next;  // di chuyển start lên một node
        free(tmp);            // giải phóng tmp
    }
}
void Priority_Queue::Display() {  // Hien thi priority queue
    node *ptr;
    ptr = start;  // ptr trỏ đến start
    if (start == NULL)
        cout << "Hàng đợi rỗng" << endl;
    else {
        cout << "Nội dung hàng đợi" << endl;
        cout << "Priority Item " << endl;
        while (ptr != NULL) {
            cout << ptr->priority << setw(10) << ptr->data << endl;
            ptr = ptr->next;
        }
    }
}