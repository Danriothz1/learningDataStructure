#include <iostream>
using namespace std;

const int N = 1e5 + 20;
int dp[N];
int n, a;
int res = 0x80000000;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
	    cin >> a;
	    dp[i] = max(dp[i-1] + a, a);
	    res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}

