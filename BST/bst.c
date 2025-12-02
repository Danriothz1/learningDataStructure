#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *l, *r;
} node;

node* create(int x){
    node *p = (node*)malloc(sizeof(node));
    p->val = x;
    p->l = NULL;
    p->r = NULL;
    return p;
}

node* find(node* t, int x){
    if(!t || t->val == x) return t;
    if (x < t->val) return find(t->l, x);
    if (x > t->val) return find(t->r, x);
}

node* insert(node* root, int x){
    if (!root) return create(x);
    if (x < root->val) root->l = insert(root->l, x);
    else if (x > root->val) root->r = insert(root->r, x);
    return root;
}

node* delete(node* root, int x){
    if (!root) return NULL;

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
