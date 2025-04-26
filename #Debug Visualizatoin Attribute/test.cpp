#include <bits/stdc++.h>
using namespace std;

int main() {
    string Visual = R"({
    "kind": { "grid": true },
    "text": "test",
    "columnLabels": [
        {
            "label": "test"
        }
    ],
    "rows": [
        {
            "label": "foo",
            "columns": [
                {
                    "content": "a",
                    "tag": "a"
                },
                {
                    "content": "b",
                    "tag": "b"
                }
            ]
        }
    ]
})";

    cout << Visual;
    return 0;
}
