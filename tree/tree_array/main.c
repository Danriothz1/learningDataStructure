#include <stdio.h>
#include "tree_array.h"

int main(){
    int op, x, k, m, n, val;
    treearr tr;
    scanf("%d %d", &n, &m);
    init(&tr, n);
    int i;
    for (i = 1; i <= n; i++) {
	scanf("%d", &val);
	update(&tr, i, val);
    }
    while (m--){
	scanf("%d %d %d", &op, &x, &k);
	if (op == 1) update(&tr, x, k);
	if (op == 2) printf("%d\n", query(&tr, k) - query(&tr, x - 1));
    }
    return 0;
}
