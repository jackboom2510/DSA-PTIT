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