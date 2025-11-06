#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10050

struct queue{
    int q[MAX_SIZE];
    int front;
    int back;
};

struct queue q1;
struct queue qm;

int max(int x, int y){
    if (x > y) return x;
    else return y;
}

void init(struct queue* p){
    memset(p->q, 0, MAX_SIZE);	
    p->front = 0;
    p->back = 0;
}

void push(struct queue *p, int t){
    p->q[++p->back] = t;
}

void pop(struct queue *p){
    p->front++;
}

int front(struct queue *p){
    return p->q[p->front + 1];
}

int back(struct queue *p){
    return p->q[p->back];
}

int empty(struct queue *p){
    if (p->front >= p->back) return 1;
    else return 0;
}

void enqueue(struct queue *p, struct queue *r, int t){
    push(p, t);
    push(r, max(back(r), t));
}

void dequeue(struct queue *p, struct queue *r){
    pop(p);
    pop(r);
    r->q[r->front + 1] = p->q[p->front + 1];
    int i = 2;
    while (r->q[r->front + i] != p->q[p->front + i]){
        r->q[r->front + i] = max(p->q[p->front + i], r->q[r->front + i - 1]);
        i++;
    }
}

int getmax(struct queue *t){
    return back(t);
}

int main(){
    int n, opt, var;
    scanf("%d", &n);
    while (n--){
    scanf("%d", &opt);
    if (opt == 1){
        scanf("%d", &var);
        enqueue(&q1, &qm, var);
    }
    else if (opt == 0) dequeue(&q1, &qm);
    else printf("%d\n", getmax(&qm));
    }
    return 0;
}


