#include <iostream>
using namespace std;

struct node {
    int info;
    struct node *next;
} *start;

class single_linked_list {
   public:
    node *create_node(int);
    void insert_begin();
    void insert_pos();
    void insert_last();
    void delete_pos();
    void sort();
    void search();
    void update();
    void reverse();
    void display();
    single_linked_list() {
        start = NULL;
    }
};

// Thao tác : tạo một node rời rạc có giá trị value cho DSLKĐ.
node *single_linked_list::create_node(int value) {
    struct node *temp;         // khai báo hai con trỏ node *temp
    temp = new (struct node);  // cấp phát miền nhớ cho temp
    if (temp == NULL) {        // nếu không đủ không gian nhớ
        cout << "Không đủ bộ nhớ để cấp phát " << endl;
        return 0;
    } else {
        temp->info = value;  // thiết lập thông tin cho node temp
        temp->next = NULL;   // thiết lập liên kết cho node temp
        return temp;         // trả lại node temp đã được thiết lập
    }
}

// Thao tác: thêm node vào đầu DSLKĐ.
void single_linked_list::insert_begin() {  // chèn node vào đầu DSLKĐ
    int value;
    cout << "Nhập giá trị node:";
    cin >> value;               // giá trị node cần chèn
    struct node *temp, *p;      // sử dụng hai con trỏ temp và p
    temp = create_node(value);  // tạo một node rời rạc có giá trị value
    if (start == NULL) {        // nếu danh sách liên kết rỗng
        start = temp;           // danh sách liên kết chính là node temp
        start->next = NULL;     // không có liêt kết với node khác
    } else {                    // nếu danh sách không rỗng
        p = start;              // p trỏ đến node đầu của start
        start = temp;           // node temp trở thành node đầu tiên của start
        start->next = p;        // các node còn lại chính là p
    }
}

// Thao tác thêm node vào cuối danh sách liên kết đơn:
void single_linked_list::insert_last() {  // thêm node vào cuối DSLKĐ
    int value;
    cout << "Nhập giá trị cho node: ";
    cin >> value;               // nhập giá trị node
    struct node *temp, *s;      // sử dung hai con trỏ temp và s
    temp = create_node(value);  // tạo node rời rạc có giá trị value
    if (start == NULL) {        // trường hợp DSLKĐ rỗng
        start = temp;
        temp->next = NULL;
    }
    s = start;                 // s trỏ đến node đầu danh sách
    while (s->next != NULL) {  // di chuyển s đến node cuối cùng
        s = s->next;
    }
    temp->next = NULL;  // temp không chỏ đi đâu nữa
    s->next = temp;     // thiết lập liên kết cho s
    cout << "Hoàn thành thêm node vào cuối " << endl;
}

// Thao tác thêm node vào vị trí pos của danh sách liên kết đơn:
void single_linked_list::insert_pos() {  // thêm node vào vị trí pos
    int value, pos, counter = 0;
    cout << "Nhap gia tri node:";
    cin >> value;
    struct node *temp, *s, *ptr;  // sử dụng ba con trỏ node
    temp = create_node(value);    // tạo node rời rạc có giá trị value
    cout << "Nhập vị trí node cần thêm: ";
    cin >> pos;
    int i;
    s = start;           // s trỏ đến node đầu tiên
    while (s != NULL) {  // đếm số node của DSLKĐ
        s = s->next;
        counter++;
        if (counter == 0) {  // trường hợp DSLK đơn rỗng
            cout << "Danh sách rỗng";
            return;
        }
        if (pos == 1) {           // nếu pos là vị trí đầu tiên
            if (start == NULL) {  // trường hợp DSLKĐ rỗng
                start = temp;
                start->next = NULL;
            } else {  // thêm node temp vào đầu DSLKĐ
                ptr = start;
                start = temp;
                start->next = ptr;
            }
        } else if (pos > 1 && pos <= counter) {  // trường hợp pos hợp lệ
            s = start;                           // s trỏ đến node đầu tiên
            for (i = 1; i < pos; i++) {          // di chuyển đến node pos-1
                ptr = s;
                s = s->next;
            }
            ptr->next = temp;
            temp->next = s;  // thiết lập liên kết cho node
        } else {
            cout << "Vượt quá giới hạn DSLKĐ" << endl;
        }
    }
}

// Thao tác loại node tại vị trí pos:
void single_linked_list::delete_pos() {  // loại node ở vị trí pos
    int pos, i, counter = 0;
    if (start == NULL) {  // nếu danh sách liê kết đơn rỗng
        cout << "Không thực hiện được" << endl;
        return;
    }
    cout << "Vị trí cần loại bỏ : ";
    cin >> pos;
    struct node *s, *ptr;
    s = start;       // s trỏ đến đầu danh sách
    if (pos == 1) {  // nếu vị trí loại bỏ là node đầu tiên
        start = s->next;
        s->next = NULL;
        free(s);
    } else {
        while (s != NULL) {  // đếm số node của DSLKĐ
            s = s->next;
            counter++;
        }
        if (pos > 0 && pos <= counter) {  // nếu vị trí pos hợp lệ
            s = start;                    // s trỏ đến node đầu của danh sách
            for (i = 1; i < pos; i++) {   // di chuyển đến vị trí pos-1
                ptr = s;
                s = s->next;
            }
            ptr->next = s->next;  // thiết lập liên kết cho node
        } else {
            cout << "Vi tri ngoai danh sach" << endl;
        }
        free(s);  // giải phóng s
        cout << "Node da bi loai bo" << endl;
    }
}

// Thao tác sửa đổi nội dung của node :
void single_linked_list::update() {  // sửa đổi thông tin của node
    int value, pos, i;
    if (start == NULL) {  // nếu danh sách LKĐ rỗng
        cout << "Không thực hiện được" << endl;
        return;
    }
    cout << "Nhập vị trí node cần sửa:";
    cin >> pos;
    cout << "Giá trị mới của node:";
    cin >> value;
    struct node *s, *ptr;  // sử dụng hai con trỏ s và ptr
    s = start;             // s trỏ đến node đầu tiên
    if (pos == 1) {
        start->info = value;
    }  // sửa luôn node đầu tiên
    else {                               // nếu pos không phải là node đầu tiên
        for (i = 0; i < pos - 1; i++) {  // chuyển s đến vị trí pos-1
            if (s == NULL) {             // Nếu s là node cuối cùng
                cout << "Vị trí " << pos << " không hợp lệ";
                return;
            }
            s = s->next;
        }
        s->info = value;  // Sửa đổi thông tin cho node
    }
    cout << "Hoàn thành việc sửa đổi " << endl;
}

// Thao tác duyệt danh sách liên kết đơn:
void single_linked_list::display() {  // hiển thị nội dung DSLKĐ
    struct node *temp;                // sử dụng một con trỏ temp
    if (start == NULL) {              // nếu danh sách rỗng
        cout << "Có gì đâu mà hiển thị" << endl;
        return;
    }
    temp = start;  // temp trỏ đến node đầu trong DSLKĐ
    cout << "Nội dung DSLKĐ: " << endl;
    while (temp != NULL) {           // lặp cho đến node cuối cùng
        cout << temp->info << "->";  // hiển thị thông tin node
        temp = temp->next;           // di chuyển đến node tiếp theo
    }
    cout << "NULL" << endl;  // node cuối cùng là NULL
}

// Thao tác tìm node trong danh sách liên kết đơn:
void single_linked_list::search() {  // Tìm kiếm node
    int value, pos = 0;
    bool flag = false;
    if (start == NULL) {  // nếu danh sách rỗng
        cout << "ta không có gì để tìm" << endl;
        return;
    }
    cout << "Nội dung node cần tìm:";
    cin >> value;
    struct node *s;
    s = start;  // s trỏ đến đầu danh sách
    while (s != NULL) {
        pos++;
        if (s->info == value) {  // Nếu s->infor là value
            flag = true;
            cout << "Tìm thấy " << value << " tại vị trí " << pos << endl;
        }
        s = s->next;
    }
    if (!flag) {  // đến cuối vẫn không thấy
        cout << "Giá trị " << value << "không tồn tại" << endl;
    }
}

// Thao tác sắp xếp các node trong danh sách liên kết đơn:
void single_linked_list::sort() {  // sắp xếp theo nội dung các node
    struct node *ptr, *s;          // sử dụng hai con trỏ ptr và s
    int value;                     // giá trị trung gian
    if (start == NULL) {           // nếu danh sách rỗng
        cout << "không có gì để sắp xếp" << endl;
        return;
    }
    ptr = start;                                       // ptr trỏ đến node đầu danh sách
    while (ptr != NULL) {                              // lặp trong khi ptr khác rỗng
        for (s = ptr->next; s != NULL; s = s->next) {  // s là node tiếp theo
            if (ptr->info > s->info) {                 // nếu điều này xảy ra
                value = ptr->info;                     // tráo đổi nội dung hai node
                ptr->info = s->info;
                s->info = value;
            }
        }
        ptr = ptr->next;
    }
}

// Thao tác đảo ngược các node của DSLKĐ:
void single_linked_list::reverse() {  // đảo ngược danh sách
    struct node *ptr1, *ptr2, *ptr3;  // sử dụng ba con trỏ node
    if (start == NULL) {              // Nếu danh sách rỗng
        cout << "ta không cần đảo" << endl;
        return;
    }
    if (start->next == NULL) {  // Nếu danh sách chỉ có một node
        cout << "đảo ngược là chính nó" << endl;
        return;
    }
    ptr1 = start;           // ptr1 trỏ đến node đầu tiên
    ptr2 = ptr1->next;      // ptr2 trỏ đến node kế tiếp của ptr1
    ptr3 = ptr2->next;      // ptr3 trỏ đến nod kế tiếp của ptr2
    ptr1->next = NULL;      // Ngắt liên kết ptr1
    ptr2->next = ptr1;      // node ptr2 bây giờ đứng trước node ptr1
    while (ptr3 != NULL) {  // Lặp nếu ptr3 khác rỗng
        ptr1 = ptr2;        // ptr1 lại bắt đầu tại vị trí ptr2
        ptr2 = ptr3;        // ptr2 bắt đầu tại vị trí ptr3
        ptr3 = ptr3->next;  // ptr3 trỏ đến node kế tiếp
        ptr2->next = ptr1;  // Thiết lập liên kết cho ptr2
    }
    start = ptr2;  // node đầu tiên bây giờ là ptr2
}

void single_linked_list::display() {  // duyệt danh sách
    struct node *temp;
    if (start == NULL) {
        cout << "Danh sách rỗng" << endl;
        return;
    }
    temp = start;
    cout << "Nội dung danh sách: " << endl;
    while (temp != NULL) {
        cout << temp->info << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {  // chương trình chính
    int choice;
    single_linked_list X;  // X là đối tượng DSLKĐ
    start = NULL;          // khởi tạo start
    while (1) {
        cout << endl << "---------------------------------" << endl;
        cout << endl << "CÁC THAO TÁC TRÊN DSLKĐ" << endl;
        cout << endl << "---------------------------------" << endl;
        cout << "1. Thêm node vào đầu danh sách" << endl;
        cout << "2. Thêm node vào cuối danh sách " << endl;
        cout << "3. Thêm node vào vị trí bất kỳ " << endl;
        cout << "4. Sắp xếp theo giá trị các ode" << endl;
        cout << "5. Loại node ở vị trí bất kỳ" << endl;
        cout << "6. Cập nhật nội dung node" << endl;
        cout << "7. Tìm kiếm node theo giá trị" << endl;
        cout << "8. Duyệt danh sách" << endl;
        cout << "9. Đảo ngược danh sách " << endl;
        cout << "0.Thoát " << endl;
        cout << "Lựa chọn chức năng: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << " Thêm node vào đầu danh sách: " << endl;
                X.insert_begin();
                cout << endl;
                break;
            case 2:
                cout << " Thêm node vào cuối danh sách: " << endl;
                X.insert_last();
                cout << endl;
                break;
            case 3:
                cout << " Thêm node vào vị trí bất kỳ:" << endl;
                X.insert_pos();
                cout << endl;
                break;
            case 4:
                cout << "Sắp xếp nội dung node: " << endl;
                X.sort();
                cout << endl;
                break;
            case 5:
                cout << "Loại bỏ node: " << endl;
                X.delete_pos();
                break;
            case 6:
                cout << "Cập nhật giá trị node:" << endl;
                X.update();
                cout << endl;
                break;
            case 7:
                cout << "Tìm kiếm node: " << endl;
                X.search();
                cout << endl;
                break;
            case 8:
                cout << "Duyệt danh sách:" << endl;
                X.display();
                cout << endl;
                break;
            case 9:
                cout << "Đảo ngược danh sách" << endl;
                X.reverse();
                cout << endl;
                break;
            case 0:
                cout << "Thoát..." << endl;
                exit(1);
                break;
            default:
                cout << "Lựa chọn sai" << endl;
                break;
        }
    }
}