#include <iostream>
#define int long long 
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

signed main() {
    int n;
    while (cin >> n) {     
        int x;
        cin >> x;
        int ans = x;

        for (int i = 1; i < n; i++) {
            cin >> x;
            ans = lcm(ans, x);
        }

        cout << ans << endl;
    }
    return 0;
}
