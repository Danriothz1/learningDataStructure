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

node* rotate_l(node *root) {
    node *child = root->r;
    node *temp = child->l; 

    child->l = root;       
    root->r = temp;        

    root->height = MAX(getheight(root->l), getheight(root->r)) + 1;
    child->height = MAX(getheight(child->l), getheight(child->r)) + 1;

    return child;
}

node* rotate_r(node *root) {
    node *child = root->l;
    node *temp = child->r; 

    child->r = root;       
    root->l = temp;        

    root->height = MAX(getheight(root->l), getheight(root->r)) + 1;
    child->height = MAX(getheight(child->l), getheight(child->r)) + 1;

    return child;
}

node* insert(node* root, int x){
    if (!root) return create(x);
    if (x < root->val) root->l = insert(root->l, x);
    else if (x > root->val) root->r = insert(root->r, x);
    else return root;
    
    root->height = 1 + MAX(getheight(root->l), getheight(root->r));
    int balance = getbalance(root);

    if (balance > 1 && x < root->l->val) return rotate_r(root);
    if (balance < -1 && x > root->r->val) return rotate_l(root);
    if (balance > 1 && x > root->l->val){
        root->l = rotate_l(root->l);
        return rotate_r(root);
    }
    if (balance < -1 && x < root->r->val){
        root->r = rotate_r(root->r);
        return rotate_l(root);
    }

    return root;
}

node* delete(node* root, int x){
    if (root == NULL) return NULL;
    if (x < root->val) root->l = delete(root->l, x);
    else if (x > root->val) root->r = delete(root->r, x);
    else{
        if (!root->l) {
            node* temp = root->r;
            free(root);
            return temp;
        }
        else if (!root->r) {
            node* temp = root->l;
            free(root);
            return temp;
        }
            node* succ = root->r;
            while (succ->l) succ = succ->l;
            root->val = succ->val;
            root->r = delete(root->r, succ->val);
        }

    root->height = 1 + MAX(getheight(root->l), getheight(root->r));
    int balance = getbalance(root);

    if (balance > 1 && getbalance(root->l) >= 0) return rotate_r(root);
    if (balance < -1 && getbalance(root->r) <= 0) return rotate_l(root);
    if (balance > 1 && getbalance(root->l) < 0){
        root->l = rotate_l(root->l);
        return rotate_r(root);
    }
    if (balance < -1 && getbalance(root->r) > 0){
        root->r = rotate_r(root->r);
        return rotate_l(root);
    }

    return root;
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
