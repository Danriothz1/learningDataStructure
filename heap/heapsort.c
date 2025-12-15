#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100050

#define lc(i) (((i) << 1) + 1)
#define rc(i) (((i) << 1) + 2)
#define pa(i) (((i) - 1) >> 1)

typedef struct heap{
	int a[N];
	int size;
}heap;

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void insert(heap *h, int val){
	if (h->size == 0){
		h->a[0] = val;
		h->size++;
		return;
	}
	int i = h->size;
	h->a[i] = val;
	while(i > 0 && h->a[i] > h->a[pa(i)]){
		swap(h->a + i, h->a + pa(i));
		i = pa(i);
	}
	h->size++;
	return;
}

int pop(heap *h){
	if (h->size == 0) return -1; 
	swap(h->a, h->a + h->size - 1);
	int i = 0;
	h->size--;
	while(lc(i) < h->size) {	
		int j = lc(i);
		if (rc(i) < h->size && h->a[rc(i)] > h->a[j]) j = rc(i);
		if (h->a[i] >= h->a[j]) break;
		swap(h->a + i, h->a + j);
		i = j;
	} 
}


void shift_down(heap *h, int i){
	while(lc(i) < h->size) {	
		int j = lc(i);
		if (rc(i) < h->size && h->a[rc(i)] > h->a[j]) j = rc(i);
		if (h->a[i] >= h->a[j]) break;
		swap(h->a + i, h->a + j);
		i = j;
	} 
}

void heapify(heap *h, int n){
	for (int k = (n >> 1) - 1; k >= 0; k--) shift_down(h, k);
}

void heapsort(heap *h){
	int s = h->size;
	heapify(h, s);
	while(h->size > 1){
		swap(h->a, h->a + h->size - 1);
		h->size--;
		shift_down(h, 0);
	}
	h->size = s;
}

int main(){
	int n;
	heap hp;
	scanf("%d", &n);
	hp.size = n;
	for (int k = 0; k < n; k++) { 
		scanf("%d", &hp.a[k]);
	}
	heapsort(&hp);
	for (int k = 0; k < n; k++) printf("%d ", hp.a[k]); 
	return 0;
}
		
