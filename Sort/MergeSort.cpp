#include <iostream>
using namespace std;

const int N = 1e5;
int a[N];
int tmp[N];
int n, ans = 0;

void msort(int l, int r){
    if (l >= r) return;
    int mid = l + r >> 1;
    msort(l, mid);
    msort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r){
	if (a[i] <= a[j]){
	    tmp[k++] = a[i++];
	}
	else{
	    tmp[k++] = a[j++];
	    ans += mid - i + 1;
	}
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int p = l; p <= r; p++) a[p] = tmp[p];
}

int main(){
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    msort(0, n-1);
    for (int i = 0; i < n; ++i) cout << a[i] <<" ";
    cout << "\n";
    cout << ans;
    return 0;
}


