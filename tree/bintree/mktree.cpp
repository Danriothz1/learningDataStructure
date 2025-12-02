#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

const int N = 1020;
typedef struct node{
    int val;
    struct node *lc;
    struct node *rc;
}node;

int find(int *a, int l, int r,int target){
    for (int i = l; i <= r; i++) {
        if (a[i] == target) return i;
    }
    return -1;
}

node* build(int* pre, int* in, int pre_l, int pre_r, int in_l, int in_r) {
    if (pre_l > pre_r) return nullptr;
    int root_val = pre[pre_l];
    node* root = new node;
    root->val = root_val;
    root->lc = nullptr;
    root->rc = nullptr;
    int k = find(in, in_l, in_r, root_val);
    int left_subtree_size = k - in_l;
    root->lc = build(pre, in, pre_l + 1, pre_l + left_subtree_size, in_l, k - 1);
    root->rc = build(pre, in, pre_l + left_subtree_size + 1, pre_r, k + 1, in_r);
    return root;
}

void postprint(node* u){
    if (u == nullptr) return;
    postprint(u->lc);
    postprint(u->rc);
    cout << u->val << " ";
}

int main(){
    int p[N];
    int i[N];
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) cin >> p[j];
    for (int j = 0; j < n; j++) cin >> i[j];
    node *root = build(p, i, 0, n-1, 0, n-1);
    postprint(root);
    return 0;
}
