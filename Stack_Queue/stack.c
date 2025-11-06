#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1024
#define OK 0
#define ERR 1
typedef int dtype;

struct stack{
    dtype st[MAX_SIZE];
    size_t top;
};

void init(struct stack *s){
    memset(s->st, 0, MAX_SIZE);
    s->top = 0;
}

void push(struct stack *s, dtype t){
    if (s->top >= MAX_SIZE) return;
    s->st[++s->top] = t;
}

dtype top(struct stack *s){
    return s->st[s->top];
}

void pop(struct stack *s){
   if (s->top == 0) return;
   s->top--;
}

struct steap{
    struct stack s;
    struct stack p;
};

void steap_init(struct steap *h){
    init(&(h->s));
    init(&(h->p));
}

void steap_push(struct steap *h, dtype t){
    push(&(h->s), t);
    if (h->s.top == 0){
        push(&(h->s), t);
        return;
    }
    dtype tp = top(&(h->p));
    if (tp > t) push(&(h->p), tp);
    else push(&(h->p), t);
}

void steap_pop(struct steap *h){
    pop(&(h->s));
    pop(&(h->p));
}

dtype steap_top(struct steap *h){
    return top(&(h->s));
}

dtype steap_max(struct steap *h){
    return top(&(h->p));
}

int main(){
    int opt, num, var;
    struct steap s;
    steap_init(&s);
    scanf("%d", &num);
    while (num--){
	scanf("%d", &opt);
	switch(opt){
	    case 1:
	    scanf("%d", &var);
	    steap_push(&s, var);
	    break;
	    case 2:
	    steap_pop(&s);
	    break;
	    case 3:
	    printf("%d\n", steap_top(&s));
	    break;
	    case 4:
	    printf("%d\n", steap_max(&s));
	    break;
	    default:
	    break;
	}
    }
    return 0;
}

