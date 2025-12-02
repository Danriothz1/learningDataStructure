#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *l, *r;
    int height;
} node;

int MAX(int a, int b) {return (a > b) ? a : b;}

int getheight(node* n){
    if (n == NULL) return 0;
    return n->height;
}

int getbalance(node *n) {
    if (n == NULL) return 0;
    return getheight(n->l) - getheight(n->r);
}

void update_height(node* n) {
    if (n != NULL) n->height = 1 + MAX(getheight(n->l), getheight(n->r));
}

node* create(int x){
    node *p = (node*)malloc(sizeof(node));
    p->val = x;
    p->l = NULL;
    p->r = NULL;
    p->height = 1;
    return p;
}

node* find(node* t, int x){
    if(!t || t->val == x) return t;
    if (x < t->val) return find(t->l, x);
    if (x > t->val) return find(t->r, x);
}

node* connect34(node* a, node* b, node* c, node* t0, node* t1, node* t2, node* t3) {
    a->l = t0; 
    a->r = t1; 
    update_height(a);

    c->l = t2; 
    c->r = t3; 
    update_height(c);

    b->l = a; 
    b->r = c; 
    update_height(b);

    return b;
}

node* rebalance(node* root) {
    int factor = getbalance(root);
    if (factor <= 1 && factor >= -1) return root;

    if (factor > 1) {
        node* L = root->l;
        if (getbalance(L) >= 0) return connect34(L->l, L, root, L->l->l, L->l->r, L->r, root->r);
        else return connect34(L, L->r, root, L->l, L->r->l, L->r->r, root->r);
    } 
    else {
        node* R = root->r;
        if (getbalance(R) <= 0) return connect34(root, R, R->r, root->l, R->l, R->r->l, R->r->r);
        else return connect34(root, R->l, R, root->l, R->l->l, R->l->r, R->r);
        }
}

node* insert(node* root, int x) {
    if (!root) return create(x);

    if (x < root->val) 
        root->l = insert(root->l, x);
    else if (x > root->val) 
        root->r = insert(root->r, x);
    else 
        return root; 

    update_height(root); 
    return rebalance(root); 
}

node* delete(node* root, int x) {
    if (!root) return NULL;
    if (x < root->val) {
        root->l = delete(root->l, x);
    } else if (x > root->val) {
        root->r = delete(root->r, x);
    } else {
        if (!root->l || !root->r) {
            node* temp = root->l ? root->l : root->r;
            free(root);
            return temp; 
        } else {
            node* succ = root->r;
            while (succ->l) succ = succ->l;
            root->val = succ->val; 
            root->r = delete(root->r, succ->val); 
        }
    }

    update_height(root); 
    return rebalance(root); 
}

void preorder(node* root){
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->l);
    preorder(root->r);
}

int main(){
    int n, a, b;
    node *root = NULL;
    scanf("%d", &n);
    while (n--){
        scanf("%d %d", &a, &b);
        if (a == 1) root = insert(root, b);
        if (a == 0) root = delete(root, b);
    }
    preorder(root);
    return 0;
}
