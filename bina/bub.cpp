#include <iostream>
using namespace std;

const int N =1010;
int a[N];
int n;

void bsort(int lo, int hi){
	while (hi > 0){
		int pos = 0;
		for (int i = 1; i < hi; i++){
			if (a[i-1] > a[i]){
				swap(a[i-1], a[i]);
				pos = i;
			}
		}
		hi = pos;
		if (pos == 1) return;
		for (int i = 0; i < n; ++i) cout << a[i] << " ";
		cout << "\n";
	}
}

int main(){
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	bsort(0, n);
	return 0;
}
