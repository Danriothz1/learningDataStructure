#include <iostream>
#include <stack>
using namespace std;

const int N = 1e7 + 50;
int h[N];
int l[N];
int r[N];
stack<int> sl, sr;
int n, ans;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i];
    sl.push(0);
    sr.push(n - 1);
    for (int j = 1; j <= n; j++) {
	int c = n - j - 1;
	while (!sl.empty() && h[j] < h[sl.top()]) {
	    l[sl.top()] = j;
	    sl.pop();
	}
	while (!sr.empty() && h[c] < h[sr.top()]) {
	    r[sr.top()] = c;
	    sr.pop();
	}
	sl.push(j);
	sr.push(c);
    }
    for (int k = 0; k < n; ++k) ans = max(ans, h[k] * (l[k] - r[k] - 1));
    cout << ans;
    return 0;
}
