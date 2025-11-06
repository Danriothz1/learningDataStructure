#include <iostream>
#include <stack>
using namespace std;

const int N = 80050;
int res = 0;
int a[N];
stack<int> s;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    s.push(0);
    for (int j = 1; j < n; j++){
	while (!s.empty() && a[s.top()] <= a[j]){
	    res += j - s.top() - 1;
	    s.pop();
	}
	s.push(j);
    }
    while (!s.empty()){
	res += n - s.top() - 1;
	s.pop();
    }
    cout << res;
    return 0;
}
