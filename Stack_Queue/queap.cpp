#include <iostream>
#define MAX_SIZE 1024
using namespace std;

struct queue{
    int q[MAX_SIZE];
    int front = 0;
    int back = 0;
};

struct queue q1, qm;

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
    cin >> n;
    while (n--){
    cin >> opt;
    if (opt == 1){
	cin >> var;
	enqueue(&q1, &qm, var);
    }
    else if (opt == 0) dequeue(&q1, &qm);
    else cout << getmax(&qm) << endl;
    }
    return 0;
}

