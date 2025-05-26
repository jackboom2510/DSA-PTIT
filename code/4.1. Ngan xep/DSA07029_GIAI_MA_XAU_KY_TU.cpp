#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Hàm giải mã một chuỗi
string decodeString(const string &s) {
    stack<string> st;
    int n = s.size();
    
    for (int i = 0; i < n; ++i) {
        if (s[i] != ']') {
            // Đẩy từng ký tự (hoặc số/chữ) vào stack
            st.push(string(1, s[i]));
        } else {
            // Khi gặp ']', bắt đầu giải mã
            string substr = "";
            while (!st.empty() && st.top() != "[") {
                substr = st.top() + substr;
                st.pop();
            }
            st.pop(); // Bỏ dấu '['

            // Lấy số lần lặp
            string numStr = "";
            while (!st.empty() && isdigit(st.top()[0]) && st.top().size() == 1) {
                numStr = st.top() + numStr;
                st.pop();
            }
            int repeat = stoi(numStr);

            // Tạo chuỗi mới và đẩy lại vào stack
            string expanded = "";
            for (int j = 0; j < repeat; ++j) {
                expanded += substr;
            }
            st.push(expanded);
        }
    }

    // Ghép kết quả từ stack
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Đọc bỏ ký tự xuống dòng
    while (T--) {
        string str;
        getline(cin, str);
        cout << decodeString(str) << endl;
    }
    return 0;
}