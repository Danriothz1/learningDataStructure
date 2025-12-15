#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 10050

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
	int res = h->a[0];
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
	return res;
}

int main(){
	int n, a, b;
	heap hp;
	hp.size = 0;
	scanf("%d", &n);
	while(n--){
		//for (int k = 0; k < hp.size; k++) printf("%d ",hp.a[k]); 
		scanf("%d", &a);
		if (a == 0) {
			scanf("%d", &b);
			insert(&hp, b);
		}
		else if (a == 1){
			int s = pop(&hp);
			printf("%d", s);
		} else{
			printf("%d", hp.size);
		}
	}
	return 0;
}
		
