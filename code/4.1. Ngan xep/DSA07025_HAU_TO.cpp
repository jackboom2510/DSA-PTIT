#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

long long evaluatePostfix(const vector<string>& tokens) {
    stack<long long> s;
    for (const string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            long long b = s.top(); s.pop();
            long long a = s.top(); s.pop();
            long long result;
            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else result = a / b; // integer division
            s.push(result);
        } else {
            // Convert token to number (can be negative or multi-digit)
            s.push(stoll(token));
        }
    }
    return s.top();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cin.ignore(); // Bỏ dòng newline sau số N

        string line;
        getline(cin, line);

        stringstream ss(line);
        string token;
        vector<string> tokens;

        while (ss >> token) {
            tokens.push_back(token);
        }

        cout << evaluatePostfix(tokens) << endl;
    }
    return 0;
}
