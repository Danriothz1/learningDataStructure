#include <iostream>
using namespace std;

const int N = 1e6+10;
int a[N];
int n, m, res;

bool check(int x){
    int sum = 0;
    for (int i = 0; i < n; ++i){
	if (a[i] > x) sum += (a[i] - x);
    }
    if (sum >= m) return true;
    else return false;
}

int main(){
    cin >> n >> m;
    int l = 0, r = 0;
    for (int i = 0;i < n; ++i){
        cin >> a[i];
        r = max(r, a[i]);
    }	
    while (l <= r){
	int mid = l + r >> 1;
	if (check(mid)) l = mid + 1;
	else r = mid - 1;
    }
    cout << l - 1;
    return 0;
}
