#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> a;
        a.push_back("0");
        a.push_back("1");
        for (int i = 2; i < (1 << n); i = i << 1)
        {
            for (int j = i - 1; j >= 0; j--)
                a.push_back(a[j]);
            for (int j = 0; j < i; j++)
                a[j] = "0" + a[j];
            for (int j = i; j < 2 * i; j++)
                a[j] = "1" + a[j];
        }
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
        cout << endl;
    }
}
/* Do Xuan Huong
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@##################@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@#############################@@@@@@@@@@@@@@@@
@@@@@@@@@@@@&####################################@@@@@@@@@@@@
@@@@@@@@@@##########################################@@@@@@@@@
@@@@@@@@##############################################@@@@@@@
@@@@@@#################################################@@@@@@
@@@@@####################################################@@@@
@@@%#####################@@@@@@@@@@@######################@@@
@@@###################@@@@@@@@@@@@@@@@@####################@@
@@##################@@@@@@         @@@@@@##################@@
@@#################@@@@@             @@@@###################@
@@@@@@@@@@@@@@@@@@@@@@@@             @@@@@@@@@@@@@@@@@@@@@@@@
@                  &@@@@             @@@@           .......@@
@@                  @@@@@@         @@@@@@           .......@@
@@                    @@@@@@@@@@@@@@@@@            .......@@@
@@@                      @@@@@@@@@@@               ......@@@@
@@@@                                              ......@@@@@
@@@@@@                                           ......@@@@@@
@@@@@@@                                         .....@@@@@@@@
@@@@@@@@@                                     .....@@@@@@@@@@
@@@@@@@@@@@@                                ....@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@                         ....@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@%                .@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
*/
