#include <bits/stdc++.h>
using namespace std;
int main() {
    fstream os("output.txt", ios::out);
    string Demo = ""
	"{"
	"    \"kind\": {\"graph\":true}, "
    "    \"nodes\": ["
	"        {\"id\":\"1\"},"
	"        {\"id\":\"2\"}], "
    "    \"edges\":["
	"        {\"from\":\"1\",\"to\":\"2\", \"color\": \"red\"}"
	"    ]"
	"}";
    string Graphiz = ""
    "{"
    "    \"kind\": { \"graph\": true },"
    "    \"nodes\":["
    "        { \"id\": \"1\", \"label\": \"1\" },"
    "        { \"id\": \"2\", \"label\": \"2\" },"
    "    ],"
    "    \"edges\":["
    "        { \"from\": \"1\", \"to\": \"2\" },"
    "        { \"from\": \"2\", \"to\": \"1\" }"
    "    ]"
    "}";
    string Grid = ""
    "{"
    "    \"kind\": { \"grid\": true },"
    "    \"text\": \"test\","
    "    \"columnLabels\": ["
    "        {"
    "            \"label\": \"test\""
    "        }"
    "    ],"
    "    \"rows\": ["
    "        {"
    "            \"label\": \"foo\","
    "            \"columns\": ["
    "                {"
    "                    \"content\": \"a\","
    "                    \"tag\": \"a\""
    "                },"
    "                {"
    "                    \"content\": \"b\","
    "                    \"tag\": \"b\""
    "                }"
    "            ]"
    "        }"
    "    ]"
    "}";
    string Plotly = ""
    "{"
    "    \"kind\":{ \"plotly\": true },"
    "    \"data\":["
    "        { \"y\": [1, 2, 4, 8, 16] },"
    "        { \"y\": [14, 3, 0, 15, 10] }"
    "    ]"
    "}";
    os << Grid;
    os.close();
    return 0;
}
