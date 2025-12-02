#include <iostream>
using namespace std;
const int N = 3e6+10;
int a[N];
int n, x;

int binary_search(int m, int l, int r){
    int res = -1;
    while (l <= r){
	int mid = l + r >> 1;
	if (a[mid] == m){
	    res = mid;
	    r = mid - 1;
	}
        else if (a[mid] < m){
	    l = mid + 1;
	}
	else{
	    r = mid - 1;
	}
    }
    return res;
}

int main(){
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    printf("%d\n",binary_search(x, 1, n));
    return 0;
}
