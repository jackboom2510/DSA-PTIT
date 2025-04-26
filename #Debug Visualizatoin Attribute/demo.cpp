#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // visualize `myGraphJson`!
    string myGraphJson = ""
	"{"
	"    \"kind\": {\"graph\":true}, "
    "    \"nodes\": ["
	"        {\"id\":\"1\", \"label\": \"One\"},"
	"        {\"id\":\"2\", \"label\": \"Two\"}], "
    "    \"edges\":["
	// "        {\"from\":\"1\",\"to\":\"2\", \"color\": \"red\"}"
	"        {\"from\":\"2\",\"to\":\"1\", \"color\": \"red\"}"
	"    ]"
	"}";
    cout << myGraphJson;
}