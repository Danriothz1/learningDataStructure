#include <iostream>
#include <deque>
#include <climits>
using namespace std;

const int N = 100050;
int s[N];
int ans = INT_MAX;
deque<int> dq;

int main(){
    int n, k, var;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
	cin >> var;
	s[i] = s[i-1] + var;
    }
    for (int j = 0; j <= n; j++){
	 while (!dq.empty() && s[j] - s[dq.front()] >= k){
	    int tmp = dq.front();
	    dq.pop_front();
	    ans = min(ans, j - tmp);
	 }
	 while (!dq.empty() && s[j] <= s[dq.back()]) dq.pop_back();
	 dq.push_back(j);
    }
    if (ans == INT_MAX) {cout << -1;return 0;}
    cout << ans;
    return 0;
}

