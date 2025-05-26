#include <iostream>
using namespace std;
#define MAXSIZE 100

typedef struct STK {    // biểu diễn stack dùng mảng
    int top;            // vị trí diễn ra các thao tác
    int node[MAXSIZE];  // các node dữ liệu của ngăn xếp
};

class STACK {  // xây dựng lớp thao tác cho stack
   public:
    STK s;                             // định nghĩa s là một stack gồm MAX node
    void push() {                      // lấy phần tử ra khỏi ngăn xếp
        int value;                     // giá trị của node
        if (s.top == (MAXSIZE - 1)) {  // nếu top ở vị trí MAX-1
            cout << "Tràn Stack" << endl;
            return;  // ta không đưa được phần tử vào ngăn xếp
        } else {     // nếu stack chưa tràn
            cout << "Nhập phần tử:";
            cin >> value;
            s.top = s.top + 1;      // dịch chuyển top lên một node
            s.node[s.top] = value;  // tại vị trí top ta lưu trữ value
        }
    }
    int pop() {  // lấy phần tử ra khỏi ngăn xếp
        int value;
        if (s.top == -1) {  // nếu stack rỗng
            cout << "Stack rỗng" << endl;
            return (INT_MIN);
        } else {                    // nếu stack không rỗng
            value = s.node[s.top];  // giá trị node cần lấy ra
            cout << "Phần tử bị loại:" << s.node[s.top] << endl;
            s.top = s.top - 1;  // giảm s.top đi 1
        }
        return (value);  // giá trị node bị lấy ra
    }
    void display() {        // duyệt stack
        if (s.top == -1) {  // nếu stack rỗng
            cout << "Ta không có gì để duyệt" << endl;
            return;
        } else {
            cout << "\n Nội dung stack: " << endl;
            for (int i = s.top; i >= 0; i--) cout << s.node[i] << setw(3);
        }
    }
    STACK(void) {    // constructor của lớp
        s.top = -1;  // thiết lập s.top là -1
    }
};

struct node {           // biểu diễn stack như một danh sách liên kết đơn
    int info;           // thông tin của node
    struct node *link;  // thành phần liên kết
} *Stack;               // danh sách liên kết đơn stack

class stack_list {  // xây dựng lớp stack_list
   public:
    node *push(node *, int);  // đưa phần tử vào ngăn xếp
    node *pop(node *);        // lấy phần tử ra khỏi ngăn xếp
    void traverse(node *);    // duyệt ngăn xếp
    stack_list() {            // constructor của lớp
        Stack = NULL;         // stack đầu tiên thiết lập lá null
    }
};
node *stack_list::push(node *Stack, int item) {  // thêm node item vào đầu stack
    node *tmp;                                   // sử dụng con trỏ tmp
    tmp = new (struct node);                     // cấp phát miền nhớ cho node tmp
    tmp->info = item;                            // thiết lập thành phần thông tin
    tmp->link = Stack;                           // thiết lập liên kết cho tmp
    Stack = tmp;                                 // tmp là node đầu danh sách
    return Stack;                                // kết quả danh sách mới
}
void stack_list::traverse(node *Stack) {  // duyệt stack
    node *ptr;
    ptr = Stack;
    if (Stack == NULL)  // nếu stack rỗng
        cout << "Stack rỗng" << endl;
    else {  // nếu stack không rỗng
        cout << "Nội dung Stack :";
        while (ptr != NULL) {
            cout << ptr->info << endl;
            ptr = ptr->link;
        }
    }
}