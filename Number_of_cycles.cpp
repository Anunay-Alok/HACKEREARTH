#include <iostream>
 
using namespace std;
 
int main()
{
    long long q, n, b;
    cin >> q;
 
    while (q--)
    {
        cin >> n;
        b = (n * (n - 1)) + 1;
        cout << b << "\n";
    }
    return 0;
}
