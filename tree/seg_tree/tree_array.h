#include <string.h>
#define MAX_SIZE 1024
#define OK 0
#define Err 1

typedef struct tree_arr{
    int a[MAX_SIZE];
    int capacity;
} treearr;

int init(treearr *p, int n){
    if (n >= MAX_SIZE) return Err;
    p -> capacity = n + 1;
    memset(p->a, 0, sizeof(p->a));
    return OK;
}

int lowbit(int x){
    return x & (-x);
}

int update(treearr *p, int x, int k){
    if (x <= 0 || x >= p -> capacity) return Err;
    while (x < p -> capacity){
	p -> a[x] += k;
       	x += lowbit(x);
    }
    return OK;
}

int query(treearr *p, int x){
    int s = 0;
    while (x > 0){
	s += p -> a[x];
	x -= lowbit(x);
    }
    return s;
}

