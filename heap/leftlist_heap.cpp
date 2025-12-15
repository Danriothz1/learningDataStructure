#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Node {
    int val;
    int npl; 
    Node *left, *right;
    Node(int v) : val(v), npl(1), left(nullptr), right(nullptr) {}
};

int get_npl(Node* node) {
    return node ? node->npl : 0;
}

Node* merge(Node* x, Node* y) {
    if (!x) return y;
    if (!y) return x;
    if (x->val > y->val) {
        swap(x, y);
    }
    x->right = merge(x->right, y);
    if (get_npl(x->left) < get_npl(x->right)) {
        swap(x->left, x->right);
    }
    x->npl = get_npl(x->right) + 1;
    return x;
}

Node* build_leftist_heap(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    
    queue<Node*> q;
    for (int val : nums) {
        q.push(new Node(val));
    }
    
    while (q.size() > 1) {
        Node* h1 = q.front(); q.pop();
        Node* h2 = q.front(); q.pop();
        q.push(merge(h1, h2));
    }
    return q.front();
}

int main() {
    int n, m;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    cin >> m;
    vector<int> B(m);
    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }
    Node* rootA = build_leftist_heap(A);
    Node* rootB = build_leftist_heap(B);
    rootA = merge(rootA, rootB);
    cout << get_npl(rootA) << endl;
    bool first = true;
    while (rootA) {
        if (!first) cout << " ";
        cout << rootA->val;
        first = false;
        Node* temp = rootA;
        rootA = merge(rootA->left, rootA->right);
        delete temp;
    }  
    return 0;
}
